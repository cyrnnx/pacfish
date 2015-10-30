#include <SFML/Graphics.hpp>
#include "ResourcePath.h"h1

void movement(sf::Sprite&, sf::RenderWindow&);
void walls(sf::Sprite&);


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Movement");


	sf::Texture characterTexture;
	characterTexture.loadFromFile(resourcePath() + "Images/alien.jpg");
	sf::Sprite characterSprite;
	characterSprite.setTexture(characterTexture);
	characterSprite.setPosition(400, 300);

	sf::Texture wall1Texture;
	wall1Texture.loadFromFile(resourcePath() + "Images/wall1.png");
	sf::Sprite wall1;
	wall1.setTexture(wall1Texture);




	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(characterSprite);
		movement(characterSprite, window);
		walls(wall1);
		window.display();

	}

	return 0;
}


void movement(sf::Sprite& character, sf::RenderWindow& window)
{
	float moveSpeed = 0.1, moveSpeedR = -0.1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		moveSpeed /= 2.2;
		moveSpeedR /= 2.2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		moveSpeed *= 2.2;
		moveSpeedR *= 2.2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		character.move(0, moveSpeedR);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		character.move(0, moveSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		character.move(moveSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		character.move(moveSpeedR, 0);
	}
}

void walls(sf::Sprite& wall1)
{

}