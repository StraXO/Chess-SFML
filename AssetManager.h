#pragma once

#include <map>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace GameEngine
{
	class AssetManager
	{
	public:
		AssetManager() = default;
		~AssetManager() = default;

		void LoadTexture(const string& name, const string& fileName);
		Texture& GetTexture(const string& name);

		void LoadFont(const string& name, const string& fileName);
		Font& GetFont(const string& name);

		void LoadImage(const string& name, const string& fileName);
		Image& GetImage(const string& name);
		
		void flushAssets();

		Text CreateText(const String& font, const String& string, Color color, int fontSize);
	private:
		map<string, Texture> _textures;
		map<string, Font> _fonts;
		map<string, Image> _images;
	};
}