#pragma once
#include "Bonus.h"
#include "Ball.h"
class SlowBall :public Bonus
{
public:
	SlowBall();//konstruktor bezargumentowy
	SlowBall(int pos_X, int pos_Y, sf::Sprite sprite1);//konstruktor kt�ry przyjmuje dwie warto�ci tylu ca�kowitego oraz grafik� bonusu
	~SlowBall();//destruktor
	void Slow(Ball &ball);//metoda typu pustego zwalnniaj�ca pi�k� kt�ra jest przs�ana jako parametru przez referencj�

private:
	int slow = -1;//zmienna typu ca�kowitego reprezentuj�ca warto�� o jak� trzeba zwolni� pi�k�
};

