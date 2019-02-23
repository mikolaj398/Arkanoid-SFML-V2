#include "Block.h"


Block::Block(int pos_X, int pos_Y,float Width, float Heigth)
{
	rect.setPosition(pos_X, pos_Y);
	rect.setSize({Width,Heigth});
	rect.setOrigin(Width / 2.0f, Heigth / 2.0f);
	rect.setFillColor(sf::Color::Yellow);
}

bool Block::IsDestroyed()
{
	return this->destroyed;
}

void Block::Destroy()
{
	this->destroyed = true;
}

sf::Vector2f Block::GetSize()
{
	return rect.getSize();
}
