#include "ExpandPaddle.h"

ExpandPaddle::ExpandPaddle(int pos_X, int pos_Y, sf::Sprite sprite1) : Bonus(pos_X, pos_Y)
{
	rect.setFillColor(sf::Color::Green);
	id = 1;
	sprite = sprite1;
}
void ExpandPaddle::Expand(Paddle &paddle)
{
	paddle.ChangeSize(this->increase); //wywułujemy funkcje do zmiany rozmiaru z przesłanej przez rekurencję paletki
}

