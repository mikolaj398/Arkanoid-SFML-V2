#include "ReverseControl.h"


ReverseControl::ReverseControl(int pos_X, int pos_Y, sf::Sprite sprite1) : Bonus(pos_X, pos_Y)
{
	rect.setFillColor(sf::Color::Color(123,123,123));
	id = 6;
	sprite = sprite1;
}

ReverseControl::ReverseControl()
{
}
ReverseControl::~ReverseControl()
{
}
