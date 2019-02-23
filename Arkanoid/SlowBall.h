#pragma once
#include "Bonus.h"
#include "Ball.h"
class SlowBall :public Bonus
{
public:
	SlowBall();//konstruktor bezargumentowy
	SlowBall(int pos_X, int pos_Y, sf::Sprite sprite1);//konstruktor który przyjmuje dwie wartoœci tylu ca³kowitego oraz grafikê bonusu
	~SlowBall();//destruktor
	void Slow(Ball &ball);//metoda typu pustego zwalnniaj¹ca pi³kê która jest przs³ana jako parametru przez referencjê

private:
	int slow = -1;//zmienna typu ca³kowitego reprezentuj¹ca wartoœæ o jak¹ trzeba zwolniæ pi³kê
};

