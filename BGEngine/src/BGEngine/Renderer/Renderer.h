#pragma once

namespace BGEngine::Renderer
{
	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginDraw();
		static void EndDraw();
	};
}