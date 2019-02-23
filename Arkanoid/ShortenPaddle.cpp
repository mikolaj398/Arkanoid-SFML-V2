#include "ShortenPaddle.h"


ShortenPaddle::ShortenPaddle(int pos_X, int pos_Y, sf::Sprite sprite1) : Bonus(pos_X, pos_Y)
{
	rect.setFillColor(sf::Color::Red);
	id = 2;
	sprite = sprite1;
}

void ShortenPaddle::Shorten(Paddle &paddle)
{
	paddle.ChangeSize(this->decrease); //wywo³uje metode paletki do zmieny wielkoœci
}