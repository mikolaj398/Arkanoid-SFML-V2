#pragma once
#include "Bonus.h"
#include "Paddle.h"
class ShortenPaddle : public Bonus
{
public:
	ShortenPaddle();//konstruktor bezargumentowy
	ShortenPaddle(int pos_X, int pos_Y, sf::Sprite sprite1);//konstruktor kt�ry przyjmuje dwie warto�ci tylu ca�kowitego oraz grafik� bonusu
	~ShortenPaddle();//destruktor
	void Shorten(Paddle &paddle);//metoda typu pustego skracaj�ca paletk� kt�ra jest przs�ana jako parametru przez referencj�

private:
	int decrease = -10;//zmienna typu ca�kowitego reprezentuj�ca warto�� o jak� trzeba skr�ci� paletk�
};



