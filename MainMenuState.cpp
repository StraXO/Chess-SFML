#include "MainMenuState.h"

#include <iostream>
#include "DEFINITIONS.h"
#include "GameState.h"

namespace GameEngine
{	
	MainMenuState::MainMenuState(game_data_ref dataRef) : _dataRef(move(dataRef))
	{
		// Load font
		_dataRef->assets.LoadFont("arial", FONT_ARIAL_FILEPATH);
	}

	void MainMenuState::Init()
	{
		// Set text
		this->_titleText = _dataRef->assets.CreateText("arial", "Ze' Chess", Color::Black, 64);
		this->_playText = _dataRef->assets.CreateText("arial", "Play", Color::Black, 42);
		this->_exitText = _dataRef->assets.CreateText("arial", "Exit", Color::Black, 42);
		
		// Set position
		this->_titleText.setPosition((SCREEN_WIDTH / 2) - (this->_titleText.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 16) * 3 - (this->_titleText.getGlobalBounds().height * 0.5f));

		this->_playText.setPosition((SCREEN_WIDTH / 2) - (this->_playText.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (this->_playText.getGlobalBounds().height * 0.5f));

		this->_exitText.setPosition((SCREEN_WIDTH / 2) - (this->_exitText.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 4) * 3 - (this->_exitText.getGlobalBounds().height * 0.5f));
	}

	void MainMenuState::HandleInput()
	{
		Event event;

		while (this->_dataRef->window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				this->_dataRef->window.close();
				break;
			default:
				break;
			}

			if (this->_dataRef->input.IsTextClicked(this->_playText, Mouse::Left, this->_dataRef->window))
			{
				this->_dataRef->state.AddState(std::unique_ptr<State>(std::make_unique<GameState>(_dataRef)), true);
			}

			if (this->_dataRef->input.IsTextClicked(this->_exitText, Mouse::Left, this->_dataRef->window))
			{
				this->_dataRef->window.close();
			}
		}
	}

	void MainMenuState::Update(float dt)
	{
		
	}
	
	void MainMenuState::Draw(float dt)
	{
		this->_dataRef->window.clear(Color::White);
		
		this->_dataRef->window.draw(this->_titleText);
		this->_dataRef->window.draw(this->_playText);
		this->_dataRef->window.draw(this->_exitText);

		this->_dataRef->window.display();
	}

	void MainMenuState::Pause()
	{
	}

	void MainMenuState::Resume()
	{
	}
}
