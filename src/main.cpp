#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include "Overlap.h"
#include <cstdlib>
using namespace std;

void handleEvent(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void draw(sf::RenderWindow& window, sf::Sprite& PacFish, sf::Sprite& Wall1)
{
	window.clear();
	window.draw(PacFish);
	window.draw(Wall1);
	window.display();
}

void handleCollision(sf::Sprite& PacFish, sf::Sprite& Wall1, sf::Vector2f& position)
{
	if (overlap(PacFish, Wall1))
	{
		PacFish.setPosition(position);

	}
}

void movement(sf::Sprite& PacFish, sf::RenderWindow& window, sf::Sprite& Wall1)
{
	float moveSpeed = 0.1, moveSpeedR = -0.1;
	sf::Vector2f currentPos = PacFish.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		moveSpeed /= 2.2;
		moveSpeedR /= 2.2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		moveSpeed *= 50;
		moveSpeedR *= 50;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		PacFish.move(0, moveSpeedR);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		PacFish.move(0, moveSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		PacFish.move(moveSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		PacFish.move(moveSpeedR, 0);
	}

	handleCollision(PacFish, Wall1, currentPos);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Movement");
	sf::Texture Fish;
	Fish.loadFromFile(resourcePath() + "assets/sprites/character_sprite2.png");
	sf::Sprite PacFish;
	PacFish.setTexture(Fish);
	PacFish.setPosition(100, 300);
	PacFish.scale(0.05, 0.05);


	sf::Texture Wall;
	Wall.loadFromFile(resourcePath() + "assets/sprites/wall.jpg");
	sf::Sprite Wall1(Wall);
	Wall1.setPosition(200, 200);
	Wall1.scale(0.3, 0.3);

	while (window.isOpen())
	{
		draw(window, PacFish, Wall1);
		movement(PacFish, window, Wall1);
	}
	return 0;
}