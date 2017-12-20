#include <graphics/sprite.h>
#include <json.hpp>
#include <engine/game_object.h>
#include <engine/engine.h>

// for convenience
using json = nlohmann::json;

int main()
{
	json sprite_json;
	sprite_json["path"] = "C:/Users/guill/Pictures/128324.png";

	mmgga::Engine engine;
	
	engine.Init();

	sf::RenderWindow* window = engine.GetWindow();

	mmgga::GameObject gameObject(engine);

	auto sprite = mmgga::Sprite::LoadSprite(sprite_json,gameObject);
	 // run the program as long as the window is open
	while (window->isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window->pollEvent(event))
		{
			// "close requested" event: we close the window
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
