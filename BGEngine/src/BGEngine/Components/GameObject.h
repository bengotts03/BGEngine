//
// Created by Ben Gotts on 10/05/2025.
//

#ifndef BGENGINE_GAMEOBJECT_H
#define BGENGINE_GAMEOBJECT_H

#include "BGPCH.h"
#include "BGEngine/Components/Component.h"

namespace BGEngine::Components {
    class GameObject {
    public:
        GameObject();
        GameObject(const std::string& name);

        void AddComponent(std::shared_ptr<Component> component);
        void RemoveComponent(std::shared_ptr<Component> component);
        std::shared_ptr<Component> GetComponent(std::shared_ptr<Component> component);
        std::shared_ptr<Component> GetOrAddComponent(std::shared_ptr<Component> component);

        std::string GetName() const { return _name; }
        void SetName(const std::string& name) { _name = name; }
    private:
        std::string _name;
        std::vector<std::shared_ptr<Component>> _components;
    };
}

#endif //BGENGINE_GAMEOBJECT_H
