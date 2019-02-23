#pragma once
#include "Bonus.h"
#include "Paddle.h"
class ExpandPaddle :public Bonus
{
public:
	ExpandPaddle();//definicja konstruktora kt�ry nie przyjmuje �adnych parametr�w
	ExpandPaddle(int pos_X, int pos_Y, sf::Sprite sprite1);//konstruktor kt�ry przyjmuje dwie warto�ci tylu ca�kowitego 
														   //oraz grafik� bonusu
	~ExpandPaddle();//destruktorr

	void Expand(Paddle &paddle);//metroda typu pustego rozszerzaj�ca paletk� przes�an� przez referencj� jako parametr
	sf::Sprite expandSprite;// zmienna typu Sprite przechowuj�ca grafik� bonusu
private:
	int increase = 10;//zmienna typu ca�kowitego przechowuj�ca warto�� powi�kszenia paletki z ka�dej strony
	sf::Texture expandTexture;// zmienna typu Texture przechowuj�ca tekstur� bonusu
};


