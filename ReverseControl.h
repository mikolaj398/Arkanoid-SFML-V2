#pragma once
#include "Bonus.h"
class ReverseControl: public Bonus
{
public:
	ReverseControl(int pos_X, int pos_Y, sf::Sprite sprite1); //konstruktor kt�ry przyjmuje dwie warto�ci tylu ca�kowitego oraz grafik� bonusu
	ReverseControl();//konstruktor bezargumentowy
	~ReverseControl();//destruktor
};

