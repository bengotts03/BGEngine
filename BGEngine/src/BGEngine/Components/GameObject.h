//
// Created by Ben Gotts on 10/05/2025.
//

#ifndef BGENGINE_GAMEOBJECT_H
#define BGENGINE_GAMEOBJECT_H

#include "BGPCH.h"
#include "BGEngine/Components/Component.h"
#include "BGEngine/Components/TransformComponent.h"

namespace BGEngine::Components {
    class GameObject {
    public:
        GameObject();
        GameObject(const std::string& name);
        ~GameObject();

        virtual void OnStart();
        virtual void OnUpdate();
        virtual void OnDestroy();

        void AddComponent(std::shared_ptr<Component> component);
        void RemoveComponent(std::shared_ptr<Component> component);
        std::shared_ptr<Component> GetComponent(std::shared_ptr<Component> component);
        std::shared_ptr<Component> GetOrAddComponent(std::shared_ptr<Component> component);

        std::string GetName() const { return _name; }
        void SetName(const std::string& name) { _name = name; }

        std::shared_ptr<TransformComponent>& GetTransform() { return _transformComponent; }
    private:
        std::string _name;
        std::vector<std::shared_ptr<Component>> _components;

        std::shared_ptr<TransformComponent> _transformComponent;

        bool _hasInitialized = false;
    };
}

#endif //BGENGINE_GAMEOBJECT_H
