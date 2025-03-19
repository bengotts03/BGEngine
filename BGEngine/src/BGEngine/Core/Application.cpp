#include "BGPCH.h"
#include "Application.h"

#include <cassert>

namespace BGEngine {

	Application* Application::instance = nullptr;

	Application::Application() {
		assert(!instance, "Application already exists!");
		instance = this;

		window = Window::Create(WindowProperties("BGEngine", 1280, 720));

		for (AppLayer* layer : layerStack)
			layer->OnStart();
	}

	Application::~Application() {
		// Shutdown any systems
		window->Shutdown();

		for (AppLayer* layer : layerStack)
			layer->OnShutdown();
	}

	void Application::Close() {
		isRunning = false;
	}

	void Application::Run() const
	{
		while (isRunning)
		{
			for (AppLayer* layer : layerStack)
				layer->OnUpdate();

			window->OnUpdate();
		}
	}
}
