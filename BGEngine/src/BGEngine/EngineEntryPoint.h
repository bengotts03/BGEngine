#pragma once

#ifdef BG_PLATFORM_WINDOWS

extern BGEngine::Application* BGEngine::CreateApp();

int main(int agrc, char** argv)
{
	auto app = BGEngine::CreateApp();
	app->Run();

	delete app;
}

#endif