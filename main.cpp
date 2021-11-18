#include <iostream>
#include "DEFINITIONS.h"
#include "Engine.h"

int main()
{
	GameEngine::Engine engine = GameEngine::Engine(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

	return EXIT_SUCCESS;
}
