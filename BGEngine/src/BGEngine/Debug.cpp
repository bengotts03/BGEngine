#include "BGPCH.h"
#include "Debug.h"

namespace BGEngine {

	std::shared_ptr<spdlog::logger> Debug::engineLogger;
	std::shared_ptr<spdlog::logger> Debug::clientLogger;

	void Debug::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		engineLogger = spdlog::stdout_color_mt("ENGINE");
		engineLogger->set_level(spdlog::level::trace);

		clientLogger = spdlog::stdout_color_mt("APP");
		clientLogger->set_level(spdlog::level::trace);
	}
}