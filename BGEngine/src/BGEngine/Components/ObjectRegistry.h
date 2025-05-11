//
// Created by Ben Gotts on 11/05/2025.
//

#ifndef BGENGINE_OBJECTREGISTRY_H
#define BGENGINE_OBJECTREGISTRY_H

#include "BGPCH.h"
#include "BGEngine/Components/GameObject.h"

namespace BGEngine::Components {
    /**
     * @brief ObjectRegistry is a singleton class that manages all game objects in the game engine.
     * It is used to create, destroy and manage game objects.
     */
    class ObjectRegistry {
    public:
        ObjectRegistry();
        ~ObjectRegistry() = default;

        static ObjectRegistry& Get() { return *instance; }

        void Register(std::shared_ptr<GameObject> gameObject);
        void Unregister(std::shared_ptr<GameObject> gameObject);
        std::shared_ptr<GameObject> GetGameObject(const std::string& name);
        const std::vector<std::shared_ptr<GameObject>>& GetAllGameObjects() const;
        void Clear();
    private:
        static ObjectRegistry* instance;

        std::vector<std::shared_ptr<GameObject>> _gameObjects;
    };
}

#endif //BGENGINE_OBJECTREGISTRY_H

