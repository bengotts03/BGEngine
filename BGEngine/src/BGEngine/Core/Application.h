#pragma once

#include "AppLayerStack.h"
#include "EngineCore.h"
#include "Window.h"
#include "BGEngine/Components/CameraComponent.h"
#include "BGEngine/UI/ImGUIAppLayer.h"
#include "BGEngine/Components/ObjectRegistry.h"
#include "BGEngine/Components/GameObject.h"

namespace BGEngine {

    struct Time{
        static double DeltaTime;
        static double TimeScale;

        Time() {
            DeltaTime = 0.0f;
            TimeScale = 1.0f;
        }
    };

	class BG_API Application
	{
	public:
		static Application& Get() { return *instance; }

		Application();
		virtual ~Application();

		void Close();

		Window& GetWindow() { return *window; }
		Components::ObjectRegistry& GetRegistry() { return *objectRegistery; }
		std::shared_ptr<Components::CameraComponent>& GetMainCamera() { return mainCamera; }
		void PushLayer(AppLayer* layer);
		void PushOverlay(AppLayer* layer);

		void Run();
	private:
		static Application* instance;
	    unique_ptr<Window> window;

		AppLayerStack layerStack;
        UI::ImGUIAppLayer* guiLayer;
        // TODO: Move this into a scene class so each scene has its own object registery
        Components::ObjectRegistry* objectRegistery;
        // TODO: Move this into a scene class so each scene has its own camera
        std::shared_ptr<Components::CameraComponent> mainCamera;

		bool isRunning = true;
	};

	BG_API Application* CreateApp();
}
