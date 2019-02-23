#include "AccelerateBall.h"


AccelerateBall::AccelerateBall(int pos_X, int pos_Y, sf::Sprite sprite1) : Bonus(pos_X, pos_Y)
{
	rect.setFillColor(sf::Color::White);
	id = 3; //ustawiamy Id
	sprite = sprite1; //ustawiamy grafikê bonusu
}

void AccelerateBall::Accelerate(Ball &ball)
{
	ball.ChangeSpeed(this->acceleration);
}


