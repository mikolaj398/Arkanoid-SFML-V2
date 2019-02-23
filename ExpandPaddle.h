#pragma once
#include "Bonus.h"
#include "Paddle.h"
class ExpandPaddle :public Bonus
{
public:
	ExpandPaddle();//definicja konstruktora który nie przyjmuje ¿adnych parametrów
	ExpandPaddle(int pos_X, int pos_Y, sf::Sprite sprite1);//konstruktor który przyjmuje dwie wartoœci tylu ca³kowitego 
														   //oraz grafikê bonusu
	~ExpandPaddle();//destruktorr

	void Expand(Paddle &paddle);//metroda typu pustego rozszerzaj¹ca paletkê przes³an¹ przez referencjê jako parametr
	sf::Sprite expandSprite;// zmienna typu Sprite przechowuj¹ca grafikê bonusu
private:
	int increase = 10;//zmienna typu ca³kowitego przechowuj¹ca wartoœæ powiêkszenia paletki z ka¿dej strony
	sf::Texture expandTexture;// zmienna typu Texture przechowuj¹ca teksturê bonusu
};


