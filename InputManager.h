#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

namespace GameEngine
{
	class InputManager
	{
	public:
		InputManager() = default;

		bool IsSpriteClicked(const Sprite& object, Mouse::Button button, RenderWindow &window) const;
		bool IsTextClicked(const Text& object, Mouse::Button button, RenderWindow &window) const;

		Vector2i GetMousePosition(RenderWindow& window) const;
	};
}
