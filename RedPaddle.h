#pragma once
#include "Paddle.h"
class RedPaddle :public Paddle
{
public:
	RedPaddle();//konstruktor bezargumentowy
	~RedPaddle();//destruktor

	Paddle secondPaddle;//zmienna typu Paddle przechowuj¹ca informacje o dodatkowej paletce
	bool direction = true;//zmienna typu logicznego przechowuj¹ca informacje o kierunku ruchu dodatkowej paletki
	void UpdateSecondPaddle();//metoda typu pustego zajmuj¹ca siê poruszaniem dodatkowej paletki
	void WhatDirection();//metoda typu pustego sprawdzaj¹ca w któr¹ stronê powinna siê poruszaæ dodatkowa paletka

private:
	const float secondPaddleWidth = 160.0f;//sta³a typu zmiennoprzecinkowego przechowuj¹ca szerokoœæ dodatkowej paletki
	const float secondpaddleHeigth = 20.0f;//sta³a typu zmiennoprzecinkowego przechowuj¹ca wysokoœæ dodatkowej paletki
	const float secondpaddleVelocity = 6.0f;//sta³a typu zmiennoprzecinkowego przechowuj¹ca szybkoœæ dodatkowej paletki
	sf::Vector2f secondVelocity{ secondpaddleVelocity, 0.0f };//sta³a typu Vector2f przechowuj¹ca kierunek dodatkowej paletki
};




