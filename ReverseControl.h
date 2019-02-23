#pragma once
#include "Bonus.h"
class ReverseControl: public Bonus
{
public:
	ReverseControl(int pos_X, int pos_Y, sf::Sprite sprite1); //konstruktor który przyjmuje dwie wartoœci tylu ca³kowitego oraz grafikê bonusu
	ReverseControl();//konstruktor bezargumentowy
	~ReverseControl();//destruktor
};

