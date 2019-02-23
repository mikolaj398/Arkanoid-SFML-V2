#include "SlowBall.h"

SlowBall::SlowBall(int pos_X, int pos_Y, sf::Sprite sprite1) : Bonus(pos_X, pos_Y)
{
	rect.setFillColor(sf::Color::Color(123,32,123));
	id = 4;
	sprite = sprite1;
}

void SlowBall::Slow(Ball &ball)
{
	ball.ChangeSpeed(this->slow); //zmmieniamy szybkoœæ pi³ki u¿ywaj¹c funkcji w klasie Ball
}

