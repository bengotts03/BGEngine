#include "BGPCH.h"
#include "glad/glad.h"

#include "Application.h"


namespace BGEngine {

	Application* Application::instance = nullptr;

	Application::Application() {
		//assert(!instance, "Application already exists!");
		instance = this;

        BG_LOG_INFO("Creating Application");

		window = Window::Create(WindowProperties("BGEngine", 1280, 720));

        BG_LOG_INFO("Created Window");

		for (AppLayer* layer : layerStack)
			layer->OnStart();

        BG_LOG_INFO("Created Layers");

        float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

        /*
		// Create a vertex array
		glGenVertexArrays(1, &vertexArray);
		glBindVertexArray(vertexArray);

		// Create a vertex buffer
		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

		// Upload the vertex data to the GPU
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// Enable the vertex attribute
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		// Create an index buffer
		// Order of vertices to draw
		glGenBuffers(1, &indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

		unsigned int indices[] = {
			0, 1, 2
		};
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
         */
	}

	Application::~Application() {
		// Shutdown any systems
		window->Shutdown();

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
	}

	void Application::Run() const
	{
		while (isRunning)
		{

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

            /*
			glBindVertexArray(vertexArray);
			// Draws indexed vertices (indices)
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
            */

			for (AppLayer* layer : layerStack)
				layer->OnUpdate();

			window->OnUpdate();
		}
	}
}
