#include "AssetManager.h"

namespace GameEngine
{
	void AssetManager::LoadTexture(const string& name, const string& fileName)
	{
		Texture texture;

		if (!texture.loadFromFile(fileName))
			throw invalid_argument("Could not load texture: " + fileName);

		this->_textures[name] = texture;
	}

	Texture &AssetManager::GetTexture(const string& name)
	{
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(const string& name, const string& fileName)
	{
		Font font;

		if (!font.loadFromFile(fileName))
			throw invalid_argument("Could not load font: " + fileName);
		
		this->_fonts[name] = font;
	}

	Font &AssetManager::GetFont(const string& name)
	{
		return this->_fonts.at(name);
	}

	void AssetManager::LoadImage(const string& name, const string& fileName)
	{
		Image image;

		if (!image.loadFromFile(fileName))
			throw invalid_argument("Could not load image: " + fileName);

		this->_images[name] = image;
	}

	Image& AssetManager::GetImage(const string& name)
	{
		return this->_images.at(name);
	}

	void AssetManager::flushAssets()
	{
		this->_textures.clear();
		this->_fonts.clear();
		this->_images.clear();
	}

	Text AssetManager::CreateText(const String& font, const String& string, const Color color, const int fontSize)
	{
		Text text;

		text.setFont(GetFont(font));
		text.setString(string);
		text.setFillColor(color);
		text.setCharacterSize(fontSize);

		return text;
	}
}
