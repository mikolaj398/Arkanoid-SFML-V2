#pragma once
#include "Bonus.h"
#include "Paddle.h"
class ShortenPaddle : public Bonus
{
public:
	ShortenPaddle();//konstruktor bezargumentowy
	ShortenPaddle(int pos_X, int pos_Y, sf::Sprite sprite1);//konstruktor który przyjmuje dwie wartoœci tylu ca³kowitego oraz grafikê bonusu
	~ShortenPaddle();//destruktor
	void Shorten(Paddle &paddle);//metoda typu pustego skracaj¹ca paletkê która jest przs³ana jako parametru przez referencjê

private:
	int decrease = -10;//zmienna typu ca³kowitego reprezentuj¹ca wartoœæ o jak¹ trzeba skróciæ paletkê
};



