#include <BGEngine.h>

class Game : public BGEngine::Application {
public:
	Game() {

	}

	~Game() {

	}
};

BGEngine::Application* BGEngine::CreateApp(){
	return new Game();
}