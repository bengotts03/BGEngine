#pragma once

#include <BGEngine.h>

class GameLayer : public BGEngine::AppLayer
{
public:
	GameLayer() : BGEngine::AppLayer("GameLayer") {}
	~GameLayer() override = default;

	void OnStart() override;
	void OnShutdown() override;
	void OnUpdate() override;
	void OnGUI() override;
};
