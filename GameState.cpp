#include <iostream>
#include <utility>
#include "GameState.h"
#include "DEFINITIONS.h"

#include "MainMenuState.h"

namespace GameEngine
{
	GameState::GameState(game_data_ref dataRef) : _dataRef(move(dataRef))
	{
		
	}

	void GameState::Init()
	{
		
	}

	void GameState::HandleInput()
	{
		Event event;

		while(this->_dataRef->window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				this->_dataRef->window.close();
				break;
			default:
				break;
			}
		}

	}

	void GameState::Update(float dt)
	{
		
	}

	void GameState::Draw(float dt)
	{
		this->_dataRef->window.clear(Color::Black);

		this->_dataRef->window.display();
	}

	void GameState::SwitchState()
	{
		this->_dataRef->state.AddState(std::unique_ptr<State>(std::make_unique<MainMenuState>(_dataRef)), true);
	}

	void GameState::Pause()
	{
	}
	
	void GameState::Resume()
	{
	}

	
}
