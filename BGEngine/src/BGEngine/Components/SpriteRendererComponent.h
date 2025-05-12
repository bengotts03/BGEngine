//
// Created by Ben Gotts on 12/05/2025.
//

#ifndef BGENGINE_SPRITERENDERERCOMPONENT_H
#define BGENGINE_SPRITERENDERERCOMPONENT_H

#include "BGPCH.h"
#include "BGEngine/Components/Component.h"

namespace BGEngine::Components {
    struct ShapesLibrary{

    };

    /**
     * @brief The SpriteRendererComponent class is responsible for rendering 2D sprites in the game world.
     * It inherits from the Component class and provides functionality to manage sprite rendering.
     */
    class SpriteRendererComponent : public Components::Component {
    public:
        SpriteRendererComponent() = default;
        ~SpriteRendererComponent() override = default;

        void OnStart() override {};
        void OnUpdate() override {};
        void OnDestroy() override {};
    };

}


#endif //BGENGINE_SPRITERENDERERCOMPONENT_H
