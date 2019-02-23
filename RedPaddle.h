#pragma once
#include "Paddle.h"
class RedPaddle :public Paddle
{
public:
	RedPaddle();//konstruktor bezargumentowy
	~RedPaddle();//destruktor

	Paddle secondPaddle;//zmienna typu Paddle przechowuj�ca informacje o dodatkowej paletce
	bool direction = true;//zmienna typu logicznego przechowuj�ca informacje o kierunku ruchu dodatkowej paletki
	void UpdateSecondPaddle();//metoda typu pustego zajmuj�ca si� poruszaniem dodatkowej paletki
	void WhatDirection();//metoda typu pustego sprawdzaj�ca w kt�r� stron� powinna si� porusza� dodatkowa paletka

private:
	const float secondPaddleWidth = 160.0f;//sta�a typu zmiennoprzecinkowego przechowuj�ca szeroko�� dodatkowej paletki
	const float secondpaddleHeigth = 20.0f;//sta�a typu zmiennoprzecinkowego przechowuj�ca wysoko�� dodatkowej paletki
	const float secondpaddleVelocity = 6.0f;//sta�a typu zmiennoprzecinkowego przechowuj�ca szybko�� dodatkowej paletki
	sf::Vector2f secondVelocity{ secondpaddleVelocity, 0.0f };//sta�a typu Vector2f przechowuj�ca kierunek dodatkowej paletki
};




