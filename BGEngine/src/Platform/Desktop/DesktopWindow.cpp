#include "BGPCH.h"
#include "DesktopWindow.h"

#include "glad/glad.h"
#include <cassert>
#include "BGEngine/Renderer/Renderer.h"

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

        glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
            //TODO: Fix this with events, but for now just access Renderer
            Graphics::Renderer::OnWindowResize(0, 0, width, height);
        });
    }

	void DesktopWindow::Shutdown()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

    // TODO: Fix this mess of a fps calculation
    // Variables for smoother FPS calculation
    double previousTime = glfwGetTime();
    double currentTime = 0.0;
    double deltaTime = 0.0;
    double averageDeltaTime = 0.0;
    const int numSamples = 100;  // Number of frames to average
    std::vector<double> frameTimes(numSamples, 0.0);
    int currentFrame = 0;
    double fps = 0.0;

    void DesktopWindow::OnUpdate()
	{
        // Calculate time between frames
        currentTime = glfwGetTime();
        deltaTime = currentTime - previousTime;
        previousTime = currentTime;

        // Store frame time in circular buffer
        frameTimes[currentFrame] = deltaTime;
        currentFrame = (currentFrame + 1) % numSamples;

        // Calculate average frame time from all samples
        averageDeltaTime = 0.0;
        for (double frameTime : frameTimes) {
            averageDeltaTime += frameTime;
        }
        averageDeltaTime /= numSamples;

        // Calculate and display FPS
        if (averageDeltaTime > 0.0) {
            fps = 1.0 / averageDeltaTime;
        }

        glfwPollEvents();
		glfwSwapBuffers(window);
	}

    double DesktopWindow::GetTime()
    {
        return glfwGetTime();
    }

    double DesktopWindow::GetFPS()
    {
        return fps;
    }

	unique_ptr<Window> DesktopWindow::Create(const WindowProperties windowProps)
	{
		return make_unique<DesktopWindow>(windowProps);
	}
}
