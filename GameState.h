#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Engine.h"

namespace GameEngine
{
	class GameState final : public State
	{
	public:
		explicit GameState(game_data_ref dataRef);

		void Init() override;

		void HandleInput() override;
		void Update(float dt) override;
		void Draw(float dt) override;

		void SwitchState();
		
		void Pause() override;
		void Resume() override;


	private:
		game_data_ref _dataRef;

		Clock _clock;
	};
}