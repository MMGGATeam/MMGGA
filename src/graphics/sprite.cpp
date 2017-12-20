/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <graphics/sprite.h>
#include <memory>
#include <experimental/filesystem>
#include <graphics/texture_manager.h>
#include <engine/engine.h>

namespace fs = std::experimental::filesystem;

namespace mmgga
{



Sprite* Sprite::LoadSprite(json componentJson, GameObject& gameObject)
{
	std::unique_ptr <mmgga::Sprite> newSprite = std::make_unique<mmgga::Sprite>(gameObject);
	if (componentJson.find("path") != componentJson.end())
	{
		newSprite->filename = componentJson["path"].get<std::string>();

		if (fs::is_regular_file(newSprite->filename))
		{
			//texture stuff

		}
		else
		{
			return nullptr;		
		}
	}
	return nullptr;
}

void Sprite::SetFilename(std::string newFilename)
{
	filename = newFilename;
}

void Sprite::Draw(sf::RenderWindow * window)
{
	window->draw(sprite);
}

void Sprite::Update(sf::Time dt)
{
}

SpriteManager::SpriteManager(GraphicsManager & graphicsManager): m_GraphicsManager(graphicsManager)
{

}

}
