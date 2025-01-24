#include "World.hpp"

void World::Spawn(int posX, int posY)
{
	vel.x = 0, vel.y = 0;

	srand(time(nullptr));
	bool choice = rand() % 2;

	if (choice)
		vel.x = -vel.x + cos(rand() % 10); // Randomize velocities

	else
		vel.x = -vel.x + cos(rand() % -10);

	ball.setPosition(posX, posY);
	ball.setFillColor(sf::Color::Red);
	ball.setRadius(10.f);
}

void World::Update()
{
	vel.y += gravity;

	ball.move(vel);
}

void World::checkCollisionWithWindow(sf::RenderWindow& window)
{
	srand(time(nullptr));

	if (ball.getPosition().y + ball.getRadius() * 2 >= window.getSize().y || ball.getPosition().y <= 0)
	{
		ball.setPosition(ball.getPosition().x, ball.getPosition().y <= 0 ? 0 : window.getSize().y - ball.getRadius() * 2);
		vel.y = -vel.y * dampingFactor;
	}

	if (ball.getPosition().x + ball.getRadius() * 2 >= window.getSize().x || ball.getPosition().x <= 0)
	{
		ball.setPosition(ball.getPosition().x <= 0 ? 0 : window.getSize().x - ball.getRadius() * 2, ball.getPosition().y);
		vel.x = -vel.x * dampingFactor;
	}
}

void World::Draw(sf::RenderWindow& window)
{
	window.draw(ball);
}

