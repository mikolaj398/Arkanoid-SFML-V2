#pragma once
#include "Bonus.h"
#include "Ball.h"
class AccelerateBall :public Bonus
{
public:
	AccelerateBall(); //definicja konstruktora który nie przyjmuje ¿adnych parametrów
	AccelerateBall(int pos_X, int pos_Y, sf::Sprite sprite1); //konstruktor który przyjmuje dwie wartoœci tylu ca³kowitego 
															  //oraz grafikê bonusu
	~AccelerateBall(); //destruktor
	void Accelerate(Ball &ball); //metoda typu pustego zwiêkszaj¹ca szybkoœæ pi³ki

private:
	int acceleration = 1; //zmienna typu ca³kowitego przechowuj¹ca wartoœæ przyœpieszenia
};

