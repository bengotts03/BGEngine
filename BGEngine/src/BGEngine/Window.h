#pragma once

#include "EngineCore.h"

using namespace std;

namespace BGEngine {
	struct WindowProperties
	{
		string title;
		unsigned int width;
		unsigned int height;

		WindowProperties(std::string title = "", int width = 1280, int height = 720)
			: title(title), width(width), height(height)
		{
		}
	};

	class BG_API Window
	{
	public:
		Window(const WindowProperties& windowProps) : windowProps(windowProps) {}
		virtual ~Window() = default;

		virtual int GetWindowWidth() const = 0;
		virtual int GetWindowHeight() const = 0;
		virtual string GetTitle() const = 0;

		virtual void Init(const WindowProperties& windowProps) = 0;
		virtual void OnUpdate() = 0;
		virtual void Shutdown() = 0;

		virtual void* GetNativeWindow() const = 0;

		static unique_ptr<Window> Create(const WindowProperties windowProps = WindowProperties());
	private:
		WindowProperties windowProps;
	};
}
