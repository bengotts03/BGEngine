#include "BGPCH.h"
#include "Application.h"

#include <cassert>

#include "Input.h"

namespace BGEngine {

	Application* Application::instance = nullptr;

	Application::Application() {
		assert(!instance, "Application already exists!");
		instance = this;

		window = Window::Create(WindowProperties("BGEngine", 1280, 720));

		BG_ENGINE_LOG_INFO(window->GetTitle());
	}

	Application::~Application() {
		// Shutdown any systems
		window->Shutdown();
	}

	void Application::Close() {
		isRunning = false;
	}

	void Application::Run() {
		while (isRunning)
		{
			window->OnUpdate();
		}
	}
}
