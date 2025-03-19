#include "GameLayer.h"
#include <BGEngine.h>

void GameLayer::OnStart() {
	BG_ENGINE_LOG_INFO("GameLayer Attached");
}

void GameLayer::OnShutdown() {
	BG_ENGINE_LOG_INFO("GameLayer Detached");
}

void GameLayer::OnUpdate() {
}