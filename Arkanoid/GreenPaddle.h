#pragma once
#include "Paddle.h"
class GreenPaddle :public Paddle
{
public:
	GreenPaddle();//konstruktor bezparametrowy
	~GreenPaddle();//destruktor
	
	void RemoveLife();//metoda typu pustego zabieraj�ca �ycie graczowi
	int HowManyLivesLeft();//metoda typu ca�kowitego zwracj�ca liczb� �y� kt�re pozosta�y graczowi
private:
	int lives = 9;//zmienna typu ca�kowitego przechowuj�ca ilo�� �y� gracza
};


