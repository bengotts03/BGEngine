#pragma once
#include "Keycode.h"

namespace BGEngine
{
	// TODO: Replace with an actual vector implementation
	struct Vector2
	{
		float x, y;
	};

	class Input
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
