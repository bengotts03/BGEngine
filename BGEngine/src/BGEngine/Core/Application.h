#pragma once

#include "AppLayerStack.h"
#include "EngineCore.h"
#include "Window.h"
#include "BGEngine/UI/ImGUIAppLayer.h"
#include "BGEngine/Components/ObjectRegistry.h"

namespace BGEngine {

    struct Time{
        static float DeltaTime;
        static float TimeScale;

        static float GetDeltaTime() { return DeltaTime; }
        static float GetTimeScale() { return TimeScale; }

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

		void PushLayer(AppLayer* layer);
		void PushOverlay(AppLayer* layer);

		void Run() const;
	private:
		static Application* instance;
	    unique_ptr<Window> window;

		AppLayerStack layerStack;
        UI::ImGUIAppLayer* guiLayer;
        Components::ObjectRegistry* objectRegistery; // TODO: Move this into a scene class so each scene has its own object registery

		bool isRunning = true;
	};

	BG_API Application* CreateApp();
}
