#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "AssetManager.h"
#include "InputManager.h"

using namespace std;
using namespace sf;

namespace GameEngine
{
	struct GameData
	{
		StateManager state;
		AssetManager assets;
		InputManager input;
		RenderWindow window;
	};

	typedef shared_ptr<GameData> game_data_ref;

	class Engine
	{
	public:
		Engine(int width, int height, const string& title);

	private:
		const float _dt = 1.0f / 120.0f;
		Clock _clock;

		game_data_ref _data = make_shared<GameData>();

		void run() const;
	};
}