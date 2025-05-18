#pragma once

#include "BGEngine/Core/Window.h"
#include "GLFW/glfw3.h"

namespace BGEngine
{
	class BG_API DesktopWindow : public Window
	{
	public:
		DesktopWindow(const WindowProperties& windowProps);
		~DesktopWindow() override;

		void Init(const WindowProperties& windowProps) override;
		void OnUpdate() override;
		void Shutdown() override;

        double GetTime() override;
        double GetFPS() override;

		void* GetNativeWindow() const override { return window; }

		static unique_ptr<Window> Create(const WindowProperties windowProps = WindowProperties());
	private:
		GLFWwindow* window;
	};
}
