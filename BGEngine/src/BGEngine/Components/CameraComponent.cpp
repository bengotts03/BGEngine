//
// Created by Ben Gotts on 14/05/2025.
//

#include "BGPCH.h"
#include "CameraComponent.h"
#include <glm/gtc/matrix_transform.hpp>
#include "BGEngine/Core/Application.h"
#include "BGEngine/Maths/Vector3.h"
#include "TransformComponent.h"
#include "BGEngine/Core/Input.h"
#include "BGEngine/Core/Window.h"

//TODO: Currently only supports orthographic projection and 2D camera movement.
namespace BGEngine::Components {

    CameraComponent::CameraComponent() {
        BG_ENGINE_LOG_INFO("Camera Component Created");

        _viewProjectionMatrix = _projectionMatrix * _viewMatrix;

    }

    void CameraComponent::OnStart() {
        BG_ENGINE_LOG_INFO("Camera Component Started");

        // Set default orthographic size (controls zoom level)
        SetOrthographicSize(50);
        
        // Set the initial view matrix
        RecalculateViewMatrix();
    }

    void CameraComponent::OnUpdate() {
        // Movement speed is now scaled by delta time for consistent speed
        float moveSpeed = 10.0f * BGEngine::Time::DeltaTime;
        
        if(Input::IsKeyDown(BGEngine::Keycode::W)) {
            _gameObject->GetTransform()->SetPosition(_gameObject->GetTransform()->GetPosition() +
                BGEngine::Maths::Vector3(0.0f, moveSpeed, 0.0f));
        }
        if(Input::IsKeyDown(BGEngine::Keycode::S)) {
            _gameObject->GetTransform()->SetPosition(_gameObject->GetTransform()->GetPosition() -
                BGEngine::Maths::Vector3(0.0f, moveSpeed, 0.0f));
        }
        if(Input::IsKeyDown(BGEngine::Keycode::A)) {
            _gameObject->GetTransform()->SetPosition(_gameObject->GetTransform()->GetPosition() -
                BGEngine::Maths::Vector3(moveSpeed, 0.0f, 0.0f));
        }
        if(Input::IsKeyDown(BGEngine::Keycode::D)) {
            _gameObject->GetTransform()->SetPosition(_gameObject->GetTransform()->GetPosition() +
                BGEngine::Maths::Vector3(moveSpeed, 0.0f, 0.0f));
        }
        
        // Add zooming with mouse wheel
        if(Input::IsKeyDown(BGEngine::Keycode::Q)) {
            SetOrthographicSize(_orthographicSize - 2);
        }
        if(Input::IsKeyDown(BGEngine::Keycode::E)) {
            SetOrthographicSize(_orthographicSize + 2);
        }

        // Recalculate the view matrix
        RecalculateViewMatrix();
    }

    void CameraComponent::OnDestroy() {
        BG_ENGINE_LOG_INFO("Camera Component Destroyed");
    }

    void CameraComponent::SetProjectionMatrix(float left, float right, float bottom, float top) {
        _projectionMatrix = glm::ortho(left, right, bottom, top);
        _viewProjectionMatrix = _projectionMatrix * _viewMatrix;
    }
    
    void CameraComponent::SetOrthographicSize(float size) {
        _orthographicSize = std::max(0.1f, size); // Prevent negative or too small values
        RecalculateProjectionMatrix();
    }
    
    void CameraComponent::RecalculateProjectionMatrix() {
        float halfSize = _orthographicSize;
        float halfWidth = halfSize * _aspectRatio;
        
        _projectionMatrix = glm::ortho(-halfWidth, halfWidth, -halfSize, halfSize);
        _viewProjectionMatrix = _projectionMatrix * _viewMatrix;
    }

    void CameraComponent::RecalculateViewMatrix() {
        // Get the position and rotation of the game object
        auto pos = _gameObject->GetTransform()->GetPosition();
        auto rot = _gameObject->GetTransform()->GetRotation();

        // TODO: Change all glm stuff to BGEngine::Maths
        glm::vec3 position = glm::vec3(pos.getX(), pos.getY(), pos.getZ());
        glm::vec3 rotation = glm::vec3(rot.getX(), rot.getY(), rot.getZ());

        glm::mat4 translation = glm::translate(glm::mat4(1.0f), position) *
                glm::rotate(glm::mat4(1.0f), glm::radians(rotation.z), glm::vec3(0, 0, 1));

        _viewMatrix = glm::inverse(translation);
        _viewProjectionMatrix = _projectionMatrix * _viewMatrix;
    }
}