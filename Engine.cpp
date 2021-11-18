#include "Engine.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	Engine::Engine(const int width, const int height, const string& title)
	{
		// Load application icon
		_data->assets.LoadImage("icon", APPLICATION_ICON_FILEPATH);
		const Image icon = _data->assets.GetImage("icon");
		
		// Create application window
		_data->window.create(VideoMode(width, height), title, Style::Close | Style::Titlebar);
		
		// Set application properties
		_data->window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
		_data->window.setFramerateLimit(144);
		
		// Add default state
		_data->state.AddState(std::unique_ptr<State>(std::make_unique<MainMenuState>(this->_data)));
		
		this->run();
	}

	void Engine::run() const
	{
		double currentTime = this->_clock.getElapsedTime().asMilliseconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->state.ProcessStateChanges();

			const double newTime = this->_clock.getElapsedTime().asMilliseconds();

			auto frameTime = static_cast<float>(newTime - currentTime);

			if (frameTime > 0.25)
				frameTime = 0.25;

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= _dt)
			{
				this->_data->state.GetActiveState()->HandleInput();
				this->_data->state.GetActiveState()->Update(_dt);

				accumulator -= _dt;
			}

			const float interpolation = accumulator / _dt;
			this->_data->state.GetActiveState()->Draw(interpolation);
		}

		this->_data->assets.flushAssets();
	}
}
