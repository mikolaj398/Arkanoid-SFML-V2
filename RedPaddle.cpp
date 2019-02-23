#include "RedPaddle.h"



RedPaddle::RedPaddle(): Paddle()
{
	//ustawienia dodatkowej paletki
	secondPaddle.rect.setSize({ this->secondPaddleWidth,this->secondpaddleHeigth });
	secondPaddle.rect.setOrigin(this->secondPaddleWidth / 2.0f, this->secondpaddleHeigth / 2.0f);
	secondPaddle.rect.setFillColor(sf::Color::Red);
	secondPaddle.rect.setPosition(windowWidth / 2.0f, windowHeigth - 10);
	
	//ustawienia paletki gracza
	rect.setFillColor(sf::Color::Red);
	active = false;
	price = 300;
	id = 1;

	if (!texture.loadFromFile(("Sprites\\redPaddle.png"))) std::cout << "Red Paddle Texture Error" << std::endl;
	sprite.setTexture(texture);

}

void RedPaddle::UpdateSecondPaddle()
{
	secondPaddle.rect.move(this->secondVelocity); //poruszanie siê dodatkowej paletki
	WhatDirection(); //funkcja pomocnicza wyzanczaj¹ca wartosc zmiennej 'direction'
	if (direction == true) secondVelocity.x = -this->secondpaddleVelocity; //direction = true ->lewo , direction = false ->prawo
	else secondVelocity.x = this->secondpaddleVelocity;
}
void RedPaddle::WhatDirection()
{
	//jeœli dodatkowa paletka dotnie lewej krawêdzi to jedzie w prawo i jeœli prawej to jedzie w lewo
	if (secondPaddle.rect.getPosition().x <= 0) this->direction=false; 
	else if (secondPaddle.rect.getPosition().x >= windowWidth) this->direction = true;
}
RedPaddle::~RedPaddle()
{
}
