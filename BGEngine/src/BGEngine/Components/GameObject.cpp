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

        ObjectRegistry::Get().Register(std::shared_ptr<GameObject>(this));;
    }

    GameObject::GameObject(const std::string& name)
        : _name(name)
    {
        ObjectRegistry::Get().Unregister(std::shared_ptr<GameObject>(this));
    }

    void GameObject::AddComponent(std::shared_ptr<Component> component)
    {
        _components.push_back(component);
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