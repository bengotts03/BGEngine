#pragma once

#ifdef BG_PLATFORM_WINDOWS

extern BGEngine::Application* BGEngine::CreateApp();

int main(int agrc, char** argv)
{
	BGEngine::Debug::Init();

	BG_ENGINE_LOG_INFO("Application Created");
	auto app = BGEngine::CreateApp();

	BG_ENGINE_LOG_INFO("Application Runtime");
	app->Run();

	BG_ENGINE_LOG_INFO("Application Shutdown");
	delete app;
}

#endif