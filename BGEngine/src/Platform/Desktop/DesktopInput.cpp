#include "BGPCH.h"

#include "BGEngine/Application.h"
#include "BGEngine/Input.h"
#include "GLFW/glfw3.h"

namespace BGEngine
{
	std::unordered_map<Keycode, bool> Input::keyStateMap;

	bool Input::IsKeyPressed(Keycode keycode)
	{
		auto state = glfwGetKey((GLFWwindow*)Application::Get().GetWindow().GetNativeWindow(), keycode) == GLFW_PRESS;

		if (state == GLFW_PRESS && !keyStateMap[keycode])
		{
			keyStateMap[keycode] = true;
			return true;
		}

		keyStateMap[keycode] = state == GLFW_PRESS;
		return false;
	}

	bool Input::IsKeyDown(Keycode keycode)
	{
		auto state = glfwGetKey((GLFWwindow*)Application::Get().GetWindow().GetNativeWindow(), keycode);
		return state == GLFW_PRESS;
	}

	bool Input::IsKeyUp(Keycode keycode)
	{
		auto state = glfwGetKey((GLFWwindow*)Application::Get().GetWindow().GetNativeWindow(), keycode) == GLFW_RELEASE;

		if (state && keyStateMap[keycode])
		{
			keyStateMap[keycode] = false;
			return true;
		}

		keyStateMap[keycode] = state;
		return false;
	}

	bool Input::IsMouseButtonPressed(Keycode button)
	{
		auto state = glfwGetMouseButton((GLFWwindow*)Application::Get().GetWindow().GetNativeWindow(), button);
		return state == GLFW_PRESS;
	}

	Vector2 Input::GetMousePosition()
	{
		double x, y;
		glfwGetCursorPos((GLFWwindow*)Application::Get().GetWindow().GetNativeWindow(), &x, &y);
		return { (float)x, (float)y };
	}

	float Input::GetMouseX()
	{
		return GetMousePosition().x;
	}

	float Input::GetMouseY()
	{
		return GetMousePosition().y;
	}
}