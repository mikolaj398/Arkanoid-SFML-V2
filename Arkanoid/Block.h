#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
class Block: public Object
{
public:
	Block(int pos_X,int pos_Y,float Width, float Heigth);//konstruktor ustawiaj�cy pozycj� oraz wielko�� bloku
	                             //przyjmuje dwa parametry typu ca�kowitego oraz dwa typu zmiennoprzecinkowego
	~Block()=default;//destruktor

	bool IsDestroyed(); //metoda typu logicznego zwracaj�ca informacje o tym czy kolcek jest zniszczony
	void Destroy();// metoda typu pustego niszcz�ca klocek
	sf::Vector2f GetSize(); //metoda typu Vector2f zwracaj�ca wielko�� kolcka

private:
	bool destroyed = false; //zmienna typu logiczego przechowuj�ca stan klocka (zniszczony lub nie)
};

