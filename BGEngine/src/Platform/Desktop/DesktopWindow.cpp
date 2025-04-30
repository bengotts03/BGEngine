#include "BGPCH.h"
#include "DesktopWindow.h"

#include "glad/glad.h"

namespace BGEngine{

	DesktopWindow::DesktopWindow(const WindowProperties& windowProps): Window(windowProps)
	{
		Init(windowProps);
	}

	DesktopWindow::~DesktopWindow()
	{
		Shutdown();
	}

	void DesktopWindow::Init(const WindowProperties& windowProps)
	{
		this->title = windowProps.title;
		this->width = windowProps.width;
		this->height = windowProps.height;

		if (!glfwInit())
		{
			BG_ENGINE_LOG_ERROR("Could not initialize GLFW!");
			return;
		}

		window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

		if (!window)
		{
			BG_ENGINE_LOG_ERROR("Could not create window!");
			return;
		}
		glfwMakeContextCurrent(window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		assert(status, "Failed to initialize GLAD");
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

	int DesktopWindow::GetWindowWidth() const
	{
		return width;
	}

	int DesktopWindow::GetWindowHeight() const
	{
		return height;
	}

	string DesktopWindow::GetTitle() const
	{
		return title;
	}

	unique_ptr<Window> DesktopWindow::Create(const WindowProperties windowProps)
	{
		return make_unique<DesktopWindow>(windowProps);
	}
	
}
