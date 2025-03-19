#pragma once

#include "AppLayerStack.h"
#include "EngineCore.h"
#include "Window.h"

namespace BGEngine {
	class BG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Close();

		Window& GetWindow() { return *window; }
		static Application& Get() { return *instance; }

		void PushLayer(AppLayer* layer) { layerStack.PushLayer(layer); }
		void PushOverlay(AppLayer* layer) { layerStack.PushOverlay(layer); }

		void Run() const;
	private:
	    unique_ptr<Window> window;
		static Application* instance;

		AppLayerStack layerStack;

		bool isRunning = true;
	};

	BG_API Application* CreateApp();
}
