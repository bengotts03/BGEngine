#pragma once

#include "../../BGEngine/Window.h"
#include <GLFW/glfw3.h>

namespace BGEngine
{
	class DesktopWindow : public Window
	{
	public:
		DesktopWindow(const WindowProperties& windowProps);
		~DesktopWindow() override;

		void Init(const WindowProperties& windowProps) override;
		void OnUpdate() override;
		void Shutdown() override;

		int GetWindowWidth() const override;
		int GetWindowHeight() const override;
		string GetTitle() const override;

		void* GetNativeWindow() const override { return window; }

		static unique_ptr<Window> Create(const WindowProperties windowProps = WindowProperties());
	private:
		GLFWwindow* window;

		int width;
		int height;
		string title;
	};
}
