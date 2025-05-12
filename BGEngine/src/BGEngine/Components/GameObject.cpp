//
// Created by Ben Gotts on 10/05/2025.
//

#include "GameObject.h"
#include "BGEngine/Components/Component.h"
#include "BGEngine/Components/ObjectRegistry.h"

namespace BGEngine::Components{

    GameObject::GameObject()
    {
        _name = "Unnamed GameObject";

        // Create a default transform component
        _transformComponent = std::make_shared<TransformComponent>();
        _components.push_back(_transformComponent);

        ObjectRegistry::Get().Register(std::shared_ptr<GameObject>(this));
    }

    GameObject::GameObject(const std::string& name)
        : _name(name)
    {
        ObjectRegistry::Get().Register(std::shared_ptr<GameObject>(this));
    }

    GameObject::~GameObject()
    {
        ObjectRegistry::Get().Unregister(std::shared_ptr<GameObject>(this));
        for (auto& component : _components)
        {
            component->OnDestroy();
        }
    }

    void GameObject::OnStart()
    {
        _hasInitialized = true;

        for (auto& component : _components)
                component->OnStart();
    }

    void GameObject::OnUpdate()
    {
        for (auto& component : _components)
            component->OnUpdate();
    }

    void GameObject::OnDestroy()
    {
        for (auto& component : _components)
            component->OnDestroy();
    }

    void GameObject::AddComponent(std::shared_ptr<Component> component)
    {
        _components.push_back(component);

        if(_hasInitialized)
            component->OnStart();
    }

    void GameObject::RemoveComponent(std::shared_ptr<Component> component)
    {
        auto it = std::remove(_components.begin(), _components.end(), component);
        if (it != _components.end())
        {
            (*it)->OnDestroy();
            _components.erase(it, _components.end());
        }
    }

    std::shared_ptr<Component> GameObject::GetComponent(std::shared_ptr<Component> component)
    {
        auto it = std::find(_components.begin(), _components.end(), component);
        if (it != _components.end())
        {
            return *it;
        }
        return nullptr;
    }

    std::shared_ptr<Component> GameObject::GetOrAddComponent(std::shared_ptr<Component> component)
    {
        auto it = std::find(_components.begin(), _components.end(), component);
        if (it != _components.end())
        {
            return *it;
        }
        else
        {
            AddComponent(component);
            return component;
        }
    }
}