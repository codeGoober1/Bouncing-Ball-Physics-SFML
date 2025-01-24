#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>

class World
{
public:
	World() = default;

	void Draw(sf::RenderWindow& window);
	void Update();
	void checkCollisionWithWindow(sf::RenderWindow& window);
	void Spawn(int posX, int posY);
private:
	sf::CircleShape ball;

	sf::Vector2f vel;
	const float gravity = 0.981f;
	const float dampingFactor = 0.80f;
};

