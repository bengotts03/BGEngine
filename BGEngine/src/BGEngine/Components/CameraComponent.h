//
// Created by Ben Gotts on 14/05/2025.
//

#ifndef BGENGINE_CAMERA_H
#define BGENGINE_CAMERA_H

#include "BGPCH.h"
#include "BGEngine/Components/Component.h"
#include "glm/glm.hpp"

namespace BGEngine::Components {
    class CameraComponent : public Component {
    public:
        CameraComponent();
        ~CameraComponent() override = default;

        void OnStart() override;
        void OnUpdate() override;
        void OnDestroy() override;

        void SetProjectionMatrix(float left, float right, float bottom, float top);
        void SetOrthographicSize(float size);
        float GetOrthographicSize() const { return _orthographicSize; }

        const glm::mat4& GetViewMatrix() const { return _viewMatrix; }
        const glm::mat4& GetProjectionMatrix() const { return _projectionMatrix; }
        const glm::mat4& GetViewProjectionMatrix() const { return _viewProjectionMatrix; }
    private:
        glm::mat4 _viewMatrix;
        glm::mat4 _projectionMatrix;
        glm::mat4 _viewProjectionMatrix;

        float _orthographicSize = 1.0f;
        float _aspectRatio = 1.0f;

        void RecalculateProjectionMatrix();
        void RecalculateViewMatrix();
    };
}

#endif //BGENGINE_CAMERA_H
