#include <BGEngine.h>
#include <BGEngine/EngineEntryPoint.h>

#include "GameLayer.h"

class GameApp : public BGEngine::Application {
public:
	GameApp(){
		PushLayer(new GameLayer());
	}

	~GameApp() = default;
};

BGEngine::Application* BGEngine::CreateApp(){
	return new GameApp();
}