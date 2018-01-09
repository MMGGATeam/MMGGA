#include <graphics/sprite.h>
#include <json.hpp>
#include <engine/game_object.h>
#include <engine/engine.h>
#include <graphics/texture_manager.h>

// for convenience
using json = nlohmann::json;

int main()
{
	
	std::string texturePath = "C:/Users/guill/Pictures/Policeman_Male.png";
	
	json sprite_json;

	sprite_json["path"] = texturePath;

	mmgga::Engine engine;

	engine.Init();

	auto graphicsManager = engine.GetGraphicsManager();
	auto spriteManager = graphicsManager->GetSpriteManager();

	sf::RenderWindow* window = engine.GetWindow();
	mmgga::GameObject gameObject(engine);

	auto sprite = spriteManager->LoadSprite(sprite_json, gameObject);

	while (window->isOpen())
	{	
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		window->clear();
		sprite->Draw(window);
		window->display();
	}
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
