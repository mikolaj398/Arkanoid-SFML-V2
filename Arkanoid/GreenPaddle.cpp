#include "GreenPaddle.h"



GreenPaddle::GreenPaddle()
{
	rect.setFillColor(sf::Color::Green);
	active = false;
	price = 400;
	id = 2;
	if (!texture.loadFromFile(("Sprites\\greenPaddle.png"))) std::cout << "Green Paddle Texture Error" << std::endl;
	sprite.setTexture(texture);
}
void GreenPaddle::RemoveLife()
{
	this->lives--;
}
int GreenPaddle::HowManyLivesLeft()
{
	return lives;
}


GreenPaddle::~GreenPaddle()
{
}
