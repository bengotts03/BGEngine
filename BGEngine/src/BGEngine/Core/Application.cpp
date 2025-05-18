#include "BGPCH.h"
#include "Application.h"

#include <memory>
#include "BGEngine/Renderer/Renderer.h"
#include "BGEngine/Renderer/Renderer2D.h"
#include "BGEngine/Renderer/ShaderManager.h"
#include "BGEngine/Maths/Vector3.h"
#include "BGEngine/UI/ImGUIAppLayer.h"

#include "BGEngine/Components/CameraComponent.h"

using namespace BGEngine::Graphics;
using namespace BGEngine::Components;

namespace BGEngine {
    double Time::DeltaTime = 0.0f;
    double Time::TimeScale = 1.0f;

	Application* Application::instance = nullptr;

	Application::Application() {
		instance = this;
        objectRegistery = new Components::ObjectRegistry();

        auto cameraObj = new GameObject();
        cameraObj->SetName("Main Camera");
        mainCamera = cameraObj->AddComponent<CameraComponent>();

		window = Window::Create(WindowProperties("BGEngine", 1280, 720));

        Renderer::Init();
        ShaderManager::Init();

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

    double lastFrameTime = 0.0;

	void Application::Run() {
        lastFrameTime = window->GetTime();
		while (isRunning)
		{
            double currentTime = window->GetTime();
            Time::DeltaTime = (currentTime - lastFrameTime) * Time::TimeScale;
            lastFrameTime = currentTime;

			Renderer::BeginDraw();
            Renderer::EndDraw();

            for (auto object : objectRegistery->GetAllGameObjects())
                object->OnUpdate();

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
