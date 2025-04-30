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

		void PushLayer(AppLayer* layer);
		void PushOverlay(AppLayer* layer);

		void Run() const;
	private:
	    unique_ptr<Window> window;
		static Application* instance;

		AppLayerStack layerStack;

		unsigned int vertexBuffer, vertexArray, indexBuffer;

		bool isRunning = true;
	};

	BG_API Application* CreateApp();
}
