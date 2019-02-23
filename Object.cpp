#include "Object.h"

//metody zwracaj¹ce granice obiektu
float Object::Left()
{
	return this->rect.getPosition().x - this->rect.getSize().x / 2.0f;
}
float Object::Right()
{
	return this->rect.getPosition().x + this->rect.getSize().x / 2.f;
}
float Object::Top()
{
	return this->rect.getPosition().y - this->rect.getSize().y / 2.0f;
}
float Object::Bottom()
{
	return this->rect.getPosition().y + this->rect.getSize().y / 2.0f;
}


void Object::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(this->rect, state);
}

sf::Vector2f Object::GetPosition()
{
	return rect.getPosition();
}
void Object::SetPosition(int pos_X, int pos_Y)
{
	rect.setPosition(pos_X, pos_Y);
}
