//
// Created by Ben Gotts on 10/05/2025.
//

#include "GameObject.h"
#include "BGEngine/Components/Component.h"
#include "BGEngine/Components/TransformComponent.h"
#include "BGEngine/Components/ObjectRegistry.h"

namespace BGEngine::Components {

    GameObject::GameObject() {
        _name = "Unnamed GameObject";

        // Create a default transform component
        _transformComponent = std::make_shared<TransformComponent>();
        _components.push_back(_transformComponent);

        ObjectRegistry::Get().Register(std::shared_ptr<GameObject>(this));
    }

    GameObject::GameObject(const std::string &name)
            : _name(name) {
        ObjectRegistry::Get().Register(std::shared_ptr<GameObject>(this));
    }

    GameObject::~GameObject() {
        ObjectRegistry::Get().Unregister(std::shared_ptr<GameObject>(this));
        for (auto &component: _components) {
            component->OnDestroy();
        }
    }

    void GameObject::OnStart() {
        _hasInitialized = true;

        for (auto &component: _components)
            component->OnStart();
    }

    void GameObject::OnUpdate() {
        for (auto &component: _components)
            component->OnUpdate();
    }

    void GameObject::OnDestroy() {
        for (auto &component: _components)
            component->OnDestroy();
    }
}