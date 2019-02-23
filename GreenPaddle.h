#pragma once
#include "Paddle.h"
class GreenPaddle :public Paddle
{
public:
	GreenPaddle();//konstruktor bezparametrowy
	~GreenPaddle();//destruktor
	
	void RemoveLife();//metoda typu pustego zabieraj¹ca ¿ycie graczowi
	int HowManyLivesLeft();//metoda typu ca³kowitego zwracj¹ca liczbê ¿yæ które pozosta³y graczowi
private:
	int lives = 9;//zmienna typu ca³kowitego przechowuj¹ca iloœæ ¿yæ gracza
};


