#pragma once
#include "Paddle.h"
#include "Ball.h"
class BluePaddle :public Paddle
{
public:
	BluePaddle(); //konstruktor bezparametrowy
	~BluePaddle();//destruktor
	Ball secondBall; //zmienna typu Ball kt�ra przechowuje infromacje o dodatkowej pi�ce
	
};

