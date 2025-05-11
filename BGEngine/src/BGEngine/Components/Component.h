//
// Created by Ben Gotts on 10/05/2025.
//

#ifndef BGENGINE_COMPONENT_H
#define BGENGINE_COMPONENT_H

#include "BGPCH.h"

namespace BGEngine::Components {
    /**
     * @brief Base class for all components in the game engine.
     * Components are used to add functionality to game objects.
     */
    class Component {
    public:
        Component();
        virtual ~Component() = default;

        /**
         * @brief Called when the component is attached to a game object.
         */
        virtual void OnStart() {}

        /**
         * @brief Called when the component is detached from a game object.
         */
        virtual void OnDestroy() {}

        /**
         * @brief Called every frame.
         */
        virtual void OnUpdate() {}
    private:
        std::string _name;
    };
}


#endif //BGENGINE_COMPONENT_H
