#include "BGPCH.h"
#include "Application.h"
#include "BGEngine/Renderer/Renderer.h"
#include "BGEngine/Renderer/Renderer2D.h"
#include "BGEngine/Renderer/ShaderManager.h"
#include "BGEngine/Maths/Vector3.h"
#include "BGEngine/UI/ImGUIAppLayer.h"

using namespace BGEngine::Graphics;
using namespace BGEngine::Components;

namespace BGEngine {

	Application* Application::instance = nullptr;

	Application::Application() {
		instance = this;
        objectRegistery = new Components::ObjectRegistry();

		window = Window::Create(WindowProperties("BGEngine", 1280, 720));

        Renderer::Init();
        ShaderManager::Init();

        // Load shaders
        // TODO: Move this to a better place, these shaders here are the default for testing
        ShaderManager::LoadShader("BasicShader", "../../ExampleGame/assets/shaders/basic.vert", "../../ExampleGame/assets/shaders/basic.frag");

        guiLayer = new UI::ImGUIAppLayer();
        PushOverlay(guiLayer);
    }

	Application::~Application() {
		// Shutdown any systems
		window->Shutdown();
        Renderer::Shutdown();

		for (AppLayer* layer : layerStack)
            layer->OnShutdown();
	}

	void Application::PushLayer(AppLayer* layer) {
		layerStack.PushLayer(layer);
		layer->OnStart();
	}

	void Application::PushOverlay(AppLayer* layer) {
		layerStack.PushOverlay(layer);
		layer->OnStart();
	}

	void Application::Close() {
		isRunning = false;

        window->Shutdown();
        Renderer::Shutdown();
	}

	void Application::Run() const
	{
		while (isRunning)
		{
			Renderer::BeginDraw();
            Renderer2D::DrawQuad(Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f), Vector3(1.0f, 0.0f, 0.0f));
            Renderer2D::DrawQuad(Vector2(1.0f, 1.0f), Vector2(1.0f, 1.0f), Vector3(0.0f, 1.0f, 0.0f));
            Renderer::EndDraw();

			for (AppLayer* layer : layerStack)
                layer->OnUpdate();

            guiLayer->Begin();
            for (AppLayer* layer : layerStack)
                layer->OnGUI();
            guiLayer->End();

			window->OnUpdate();
		}
	}
}
