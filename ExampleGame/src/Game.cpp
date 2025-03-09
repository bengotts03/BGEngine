#include "BGPCH.h"
#include <BGEngine.h>

class Game : public BGEngine::Application {
public:
	Game() = default;

	~Game() override
	{
		
	}
};

BGEngine::Application* BGEngine::CreateApp(){
	return new Game();
}