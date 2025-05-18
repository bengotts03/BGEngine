//
// Created by Ben Gotts on 10/05/2025.
//

#ifndef BGENGINE_GAMEOBJECT_H
#define BGENGINE_GAMEOBJECT_H

#include "BGPCH.h"
#include "BGEngine/Components/Component.h"
#include "TransformComponent.h"

namespace BGEngine::Components {
class GameObject {
    public:
        GameObject();
        GameObject(const std::string& name);
        ~GameObject();

        virtual void OnStart();
        virtual void OnUpdate();
        virtual void OnDestroy();

        // Template method declarations
        template<typename T>
        void AddComponent(std::shared_ptr<T> component);
        
        template<typename T>
        std::shared_ptr<T> AddComponent();
        
        template<typename T>
        std::shared_ptr<T> GetComponent();

        std::string GetName() const { return _name; }
        void SetName(const std::string& name) { _name = name; }

        std::shared_ptr<TransformComponent>& GetTransform() { return _transformComponent; }
    private:
        std::string _name;
        std::vector<std::shared_ptr<Component>> _components;
        std::shared_ptr<TransformComponent> _transformComponent;

        bool _hasInitialized = false;
    };


    template<typename T>
    void GameObject::AddComponent(std::shared_ptr<T> component) {
        static_assert(std::is_base_of<Component, T>::value, "T must be a subclass of Component");
        component->SetGameObject(this);
        _components.push_back(component);

        if(_hasInitialized)
            component->OnStart();
    }

    template<typename T>
    std::shared_ptr<T> GameObject::AddComponent() {
        static_assert(std::is_base_of<Component, T>::value, "T must be a subclass of Component");

        auto component = std::make_shared<T>();
        AddComponent<T>(component);
        return component;
    }

    template<typename T>
    std::shared_ptr<T> GameObject::GetComponent() {
        static_assert(std::is_base_of<Component, T>::value, "T must be a subclass of Component");

        for (auto &component: _components) {
            auto result = std::dynamic_pointer_cast<T>(component);
            if (result) {
                return result;
            }
        }
        return nullptr;
    }
}

#endif //BGENGINE_GAMEOBJECT_H