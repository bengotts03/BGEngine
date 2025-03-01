#pragma once

#include "EngineCore.h"

namespace BGEngine {
	class BG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApp();
}

