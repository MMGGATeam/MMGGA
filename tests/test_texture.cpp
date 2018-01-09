
#include <graphics/graphics.h>
#include <graphics/texture_manager.h>

int main()
{
	
	std::string texture1 = "C:/Users/guill/Pictures/Policeman_Male.png";

	mmgga::Engine engine;
	auto graphicsManager = engine.GetGraphicsManager();
	auto textureManager = graphicsManager->GetTextureManager();

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Test Texture");
	textureManager->LoadTexture(texture1);
	sf::Sprite sprite;
	auto texture = textureManager->GetTexture(texture1);

	if (texture != nullptr)
	{
		sprite.setTexture(*texture);
		sprite.setPosition(sf::Vector2f(800, 100));
	}
	 // run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}
