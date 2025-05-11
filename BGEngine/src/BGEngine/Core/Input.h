#pragma once
#include "Keycode.h"
#include "BGEngine/Maths/Vector2.h"

using namespace BGEngine::Maths;

namespace BGEngine
{
	class BG_API Input
	{
	public:
		// Tapped
		static bool IsKeyPressed(Keycode keycode);
		// Held
		static bool IsKeyDown(Keycode keycode);
		// Released
		static bool IsKeyUp(Keycode keycode);

		static bool IsMouseButtonPressed(Keycode button);

		static Vector2 GetMousePosition();

		static float GetMouseX();
		static float GetMouseY();
	private:
		static std::unordered_map<Keycode, bool> keyStateMap;
	};
}
