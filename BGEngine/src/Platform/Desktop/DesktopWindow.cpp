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

	void DesktopWindow::Init(const WindowProperties& windowProps) {
        if (!glfwInit()) {
            BG_ENGINE_LOG_ERROR("Could not initialize GLFW!");
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if BG_PLATFORM_MACOS
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        window = glfwCreateWindow(windowProps.width, windowProps.height, windowProps.title.c_str(), nullptr, nullptr);

        if (!window) {
            BG_ENGINE_LOG_ERROR("Could not create window!");
            return;
        }
        // TODO: Seperate gl specific code from window code, should be moved into a RendererContext class
        glfwMakeContextCurrent(window);

        BG_ENGINE_LOG_INFO("Created window");

        int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        if (!status) {
            BG_ENGINE_LOG_ERROR("Failed to initialize GLAD");
            return;
        }
    }

	void DesktopWindow::Shutdown()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void DesktopWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	unique_ptr<Window> DesktopWindow::Create(const WindowProperties windowProps)
	{
		return make_unique<DesktopWindow>(windowProps);
	}
}
