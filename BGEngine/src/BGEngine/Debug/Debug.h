#pragma once

#include "BGEngine/Core/EngineCore.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace BGEngine {
	class BG_API Debug
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return engineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> engineLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

#define BG_ENGINE_LOG_INFO(...)	BGEngine::Debug::GetEngineLogger()->info(__VA_ARGS__)
#define BG_ENGINE_LOG_WARN(...)	BGEngine::Debug::GetEngineLogger()->warn(__VA_ARGS__)
#define BG_ENGINE_LOG_ERROR(...)	BGEngine::Debug::GetEngineLogger()->error(__VA_ARGS__)
#define BG_ENGINE_LOG_FATAL(...)	BGEngine::Debug::GetEngineLogger()->critical(__VA_ARGS__)

#define BG_LOG_INFO(...)			BGEngine::Debug::GetClientLogger()->info(__VA_ARGS__)
#define BG_LOG_WARN(...)			BGEngine::Debug::GetClientLogger()->warn(__VA_ARGS__)
#define BG_LOG_ERROR(...)			BGEngine::Debug::GetClientLogger()->error(__VA_ARGS__)
#define BG_LOG_FATAL(...)			BGEngine::Debug::GetClientLogger()->critical(__VA_ARGS__)