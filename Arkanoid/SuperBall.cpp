#include "SuperBall.h"

SuperBall::SuperBall(int pos_X, int pos_Y, sf::Sprite sprite1) : Bonus(pos_X, pos_Y)
{
	rect.setFillColor(sf::Color::Cyan);
	id = 5;
	sprite = sprite1;
}

void SuperBall::Restart()
{
	superBallClock.restart(); //restertuje zegar
}
int SuperBall::ElapsedTime()
{
	return this->superBallElapsedTime.asSeconds(); //zwraca czas który min¹ od zrestartowania zegara w sekundach
}
void SuperBall::GetTime()
{
	this->superBallElapsedTime = superBallClock.getElapsedTime();	//do zmiennej w klasie przisuje czas który min¹ od zrestartowania zegara 
}
int SuperBall::Duration()
{
	return this->duration; //zwraca czas trwania bonusu
}

