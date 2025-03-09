#include "BGPCH.h"
#include "BGEngine/Window.h"

//#ifdef BG_PLATFORM_WINDOWS
#include "Platform/Desktop/DesktopWindow.h"
//#endif

namespace BGEngine
{
    unique_ptr<Window> Window::Create(const WindowProperties windowProps) {
		// #ifdef BG_PLATFORM_WINDOWS
        return DesktopWindow::Create(windowProps);
    }
}