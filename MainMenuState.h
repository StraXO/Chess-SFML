#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Engine.h"

namespace GameEngine
{
	class MainMenuState final : public State
	{
	public:
		explicit MainMenuState(game_data_ref dataRef);

		void Init() override;

		void HandleInput() override;
		void Update(float dt) override;
		void Draw(float dt) override;

		void Pause() override;
		void Resume() override;
		
	private:
		game_data_ref _dataRef;

		Text _titleText;
		Text _playText;
		Text _exitText;
	};
}