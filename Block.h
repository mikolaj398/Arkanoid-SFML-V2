#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
class Block: public Object
{
public:
	Block(int pos_X,int pos_Y,float Width, float Heigth);//konstruktor ustawiaj¹cy pozycjê oraz wielkoœæ bloku
	                             //przyjmuje dwa parametry typu ca³kowitego oraz dwa typu zmiennoprzecinkowego
	~Block()=default;//destruktor

	bool IsDestroyed(); //metoda typu logicznego zwracaj¹ca informacje o tym czy kolcek jest zniszczony
	void Destroy();// metoda typu pustego niszcz¹ca klocek
	sf::Vector2f GetSize(); //metoda typu Vector2f zwracaj¹ca wielkoœæ kolcka

private:
	bool destroyed = false; //zmienna typu logiczego przechowuj¹ca stan klocka (zniszczony lub nie)
};

