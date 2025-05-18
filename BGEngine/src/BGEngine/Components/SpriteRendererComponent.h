//
// Created by Ben Gotts on 12/05/2025.
//

#ifndef BGENGINE_SPRITERENDERERCOMPONENT_H
#define BGENGINE_SPRITERENDERERCOMPONENT_H

#include "BGPCH.h"
#include "BGEngine/Components/Component.h"
#include "BGEngine/Renderer/Sprite.h"

using namespace BGEngine::Graphics;

namespace BGEngine::Components {
    struct ShapesLibrary{

    };

    /**
     * @brief The SpriteRendererComponent class is responsible for rendering 2D sprites in the game world.
     * It inherits from the Component class and provides functionality to manage sprite rendering.
     */
    class SpriteRendererComponent : public Components::Component {
    public:
        SpriteRendererComponent();
        SpriteRendererComponent(Sprite sprite);
        ~SpriteRendererComponent() override = default;

        void OnStart() override {};
        void OnUpdate() override;
        void OnDestroy() override {};

        void SetSprite(const Sprite& sprite) { _sprite = sprite; }
        const Sprite& GetSprite() const { return _sprite; }

        void SetColour(const Colour& colour) { _sprite.SetColour(colour); }
    private:
        Sprite _sprite;
        void DrawSprite();
    };

}


#endif //BGENGINE_SPRITERENDERERCOMPONENT_H
