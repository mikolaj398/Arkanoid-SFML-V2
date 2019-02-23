#include "Bonus.h"
#include <iostream>


Bonus::Bonus(int pos_X, int pos_Y)
{
	rect.setPosition(pos_X, pos_Y);
	rect.setSize({ bonusWidth,bonusHeigth });
	rect.setOrigin(this->bonusWidth / 2.0f, this->bonusHeigth / 2.0f);
	this->destroyed = false;
}
void Bonus::MoveDown()
{
	rect.move(this->velocity); 
	sprite.setPosition(rect.getPosition().x, rect.getPosition().y);
}
void Bonus::Destroy()
{
	this->destroyed = true;
}
bool Bonus::IsDestroyed()
{
	return this->destroyed;
}
int Bonus::GetId()
{
	return this->id;
}
Bonus::~Bonus()
{
}
