#include "World.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Bouncing Ball Physics");
	sf::Event event;

	window.setFramerateLimit(60);

	World world;

	while (window.isOpen())
	{
		sf::Vector2i pos = sf::Mouse::getPosition(window);

		while (window.pollEvent(event))
		{
			if (event.type == event.Closed())
				window.close();

			if (event.type == event.MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					world.Spawn(pos.x, pos.y);
				}
			}
		}
		world.Update();
		world.checkCollisionWithWindow(window);

		window.clear();
		world.Draw(window);
		window.display();
	}
}
