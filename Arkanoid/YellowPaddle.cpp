#include "YellowPaddle.h"



YellowPaddle::YellowPaddle()
{
	rect.setFillColor(sf::Color::Yellow);
	active = false;
	price = 200;
	id = 0;
	if (!texture.loadFromFile(("Sprites\\yellowPaddle.png"))) std::cout << "Yellow Paddle Texture Error" << std::endl;
	sprite.setTexture(texture);

}
