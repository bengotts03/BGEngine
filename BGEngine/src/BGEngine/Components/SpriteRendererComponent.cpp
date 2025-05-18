//
// Created by Ben Gotts on 12/05/2025.
//

#include "SpriteRendererComponent.h"

#include "BGEngine/Components/GameObject.h"
#include "BGEngine/Components/TransformComponent.h"
#include "BGEngine/Renderer/Renderer2D.h"
#include "BGEngine/Renderer/Sprite.h"

using namespace BGEngine::Graphics;
using namespace BGEngine::Maths;

namespace BGEngine::Components {

    SpriteRendererComponent::SpriteRendererComponent() {
        _sprite = Sprite();
    }

    SpriteRendererComponent::SpriteRendererComponent(Sprite sprite) : _sprite(sprite) {

    }

    void SpriteRendererComponent::OnUpdate() {
        DrawSprite();
    }

    /**
     * @brief Draws the sprite using the Renderer2D class.
     * This function is called to render the sprite on the screen.
     */
    void SpriteRendererComponent::DrawSprite() {
        auto transform = _gameObject->GetTransform();

        Renderer2D::DrawQuad(transform->GetPosition().ToVector2(), transform->GetScale().ToVector2(), _sprite.GetColour());
    }
}