#include "BGPCH.h"
#include "DesktopWindow.h"

#include "glad/glad.h"
#include <cassert>

namespace BGEngine{

	DesktopWindow::DesktopWindow(const WindowProperties& windowProps) : Window(windowProps)
	{
		Init(windowProps);
	}

	DesktopWindow::~DesktopWindow()
	{
		Shutdown();
	}

	void DesktopWindow::Init(const WindowProperties& windowProps)
	{
		if (!glfwInit())
		{
			BG_ENGINE_LOG_ERROR("Could not initialize GLFW!");
			return;
		}

		window = glfwCreateWindow(windowProps.width, windowProps.height, windowProps.title.c_str(), nullptr, nullptr);

		if (!window)
		{
			BG_ENGINE_LOG_ERROR("Could not create window!");
			return;
		}
		glfwMakeContextCurrent(window);

        BG_ENGINE_LOG_INFO("Created window");

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if(!status)
        {
            BG_ENGINE_LOG_ERROR("Failed to initialize GLAD");
            return;
        }
	}

	void DesktopWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void DesktopWindow::Shutdown()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	unique_ptr<Window> DesktopWindow::Create(const WindowProperties windowProps)
	{
		return make_unique<DesktopWindow>(windowProps);
	}
}
