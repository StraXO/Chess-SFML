#include "InputManager.h"

namespace GameEngine
{
	bool InputManager::IsSpriteClicked(const Sprite& object, const Mouse::Button button, RenderWindow& window) const
	{
		if(Mouse::isButtonPressed(button))
		{
			const FloatRect rect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (rect.contains(Vector2f(Mouse::getPosition(window))))
				return true;
		}
		
		return false;
	}

	bool InputManager::IsTextClicked(const Text& object, const Mouse::Button button, RenderWindow& window) const
	{
		if (Mouse::isButtonPressed(button))
		{
			const FloatRect rect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (rect.contains(Vector2f(Mouse::getPosition(window))))
				return true;
		}

		return false;
	}

	Vector2i InputManager::GetMousePosition(RenderWindow& window) const
	{
		return Mouse::getPosition(window);
	}
}
