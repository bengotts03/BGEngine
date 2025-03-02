#pragma once

#ifdef BG_PLATFORM_WINDOWS

extern BGEngine::Application* BGEngine::CreateApp();

int main(int agrc, char** argv)
{
	std::cout << "Init" << std::endl;
	std::cout << "Init 2" << std::endl;

	auto app = BGEngine::CreateApp();
	app->Run();

	delete app;
}

#endif