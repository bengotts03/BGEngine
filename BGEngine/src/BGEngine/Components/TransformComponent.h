//
// Created by Ben Gotts on 11/05/2025.
//

#ifndef BGENGINE_TRANSFORMCOMPONENT_H
#define BGENGINE_TRANSFORMCOMPONENT_H

#include "BGPCH.h"
#include "BGEngine/Maths/Vector3.h"
#include "BGEngine/Components/Component.h"

namespace BGEngine::Components {
    class TransformComponent : public Component {
    public:
        TransformComponent();
        TransformComponent(const BGEngine::Maths::Vector3& position, const BGEngine::Maths::Vector3& rotation,
                           const BGEngine::Maths::Vector3& scale);
        ~TransformComponent() override = default;

        void OnStart() override {};
        void OnUpdate() override {};
        void OnDestroy() override {};

        BGEngine::Maths::Vector3 GetPosition() const { return _position; }
        void SetPosition(const BGEngine::Maths::Vector3 &position) { _position = position; }

        BGEngine::Maths::Vector3 GetRotation() const { return _rotation; }
        void SetRotation(const BGEngine::Maths::Vector3 &rotation) { _rotation = rotation; }

        BGEngine::Maths::Vector3 GetScale() const { return _scale; }
        void SetScale(const BGEngine::Maths::Vector3 &scale) { _scale = scale; }
    private:
        BGEngine::Maths::Vector3 _position;
        BGEngine::Maths::Vector3 _rotation;
        BGEngine::Maths::Vector3 _scale;
    };
}

#endif //BGENGINE_TRANSFORMCOMPONENT_H
