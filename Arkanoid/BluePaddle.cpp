#include "BluePaddle.h"



BluePaddle::BluePaddle()
{
	secondBall.ChangeColor(sf::Color::Blue); //ustawiamy kolor dodatkowej pi�ki
	rect.setFillColor(sf::Color::Blue); //ustawiamy kolor paletki
	active = false;
	price = 500;
	id = 3;

	//wczytujemy textur� z pliku
	if (!texture.loadFromFile(("Sprites\\bluePaddle.png"))) std::cout << "Blue Paddle Texture Error" << std::endl;
	sprite.setTexture(texture);
}

