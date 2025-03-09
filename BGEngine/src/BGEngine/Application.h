#pragma once

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

		void Run();
	private:
	    unique_ptr<Window> window;
		static Application* instance;

		bool isRunning = true;
	};

	BG_API Application* CreateApp();
}
