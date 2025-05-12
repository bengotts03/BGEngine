//
// Created by Ben Gotts on 11/05/2025.
//

#include "TransformComponent.h"

namespace BGEngine::Components {

    TransformComponent::TransformComponent()
            : _position(0.0f, 0.0f, 0.0f), _rotation(0.0f, 0.0f, 0.0f), _scale(1.0f, 1.0f, 1.0f) {
    }

    TransformComponent::TransformComponent(const Maths::Vector3 &position, const Maths::Vector3 &rotation,
                                           const Maths::Vector3 &scale)
            : _position(position), _rotation(rotation), _scale(scale) {
    }
}