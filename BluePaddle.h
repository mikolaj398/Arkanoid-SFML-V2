#pragma once
#include "Paddle.h"
#include "Ball.h"
class BluePaddle :public Paddle
{
public:
	BluePaddle(); //konstruktor bezparametrowy
	~BluePaddle();//destruktor
	Ball secondBall; //zmienna typu Ball która przechowuje infromacje o dodatkowej pi³ce
	
};

