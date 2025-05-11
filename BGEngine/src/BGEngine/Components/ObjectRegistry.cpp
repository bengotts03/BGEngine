//
// Created by Ben Gotts on 11/05/2025.
//

#include "ObjectRegistry.h"

namespace BGEngine::Components {
    ObjectRegistry* ObjectRegistry::instance = nullptr;

    ObjectRegistry::ObjectRegistry() {
        instance = this;
    }

    void ObjectRegistry::Register(std::shared_ptr<GameObject> gameObject) {
        _gameObjects.push_back(gameObject);
    }

    void ObjectRegistry::Unregister(std::shared_ptr<GameObject> gameObject) {
        auto it = std::remove(_gameObjects.begin(), _gameObjects.end(), gameObject);
        if (it != _gameObjects.end()) {
            _gameObjects.erase(it, _gameObjects.end());
        }
    }

    std::shared_ptr<GameObject> ObjectRegistry::GetGameObject(const std::string &name) {
        for (const auto &gameObject: _gameObjects) {
            if (gameObject->GetName() == name) {
                return gameObject;
            }
        }
        return nullptr;
    }

    const std::vector<std::shared_ptr<GameObject>>& ObjectRegistry::GetAllGameObjects() const {
        return _gameObjects;
    }

    void ObjectRegistry::Clear() {
        _gameObjects.clear();
    }
}
