#pragma once
#include "Bonus.h"
#include "Ball.h"
class AccelerateBall :public Bonus
{
public:
	AccelerateBall(); //definicja konstruktora kt�ry nie przyjmuje �adnych parametr�w
	AccelerateBall(int pos_X, int pos_Y, sf::Sprite sprite1); //konstruktor kt�ry przyjmuje dwie warto�ci tylu ca�kowitego 
															  //oraz grafik� bonusu
	~AccelerateBall(); //destruktor
	void Accelerate(Ball &ball); //metoda typu pustego zwi�kszaj�ca szybko�� pi�ki

private:
	int acceleration = 1; //zmienna typu ca�kowitego przechowuj�ca warto�� przy�pieszenia
};

