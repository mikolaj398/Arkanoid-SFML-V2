#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
class Block: public Object
{
public:
	Block(int pos_X,int pos_Y,float Width, float Heigth);//konstruktor ustawiający pozycję oraz wielkość bloku
	                             //przyjmuje dwa parametry typu całkowitego oraz dwa typu zmiennoprzecinkowego
	~Block()=default;//destruktor

	bool IsDestroyed(); //metoda typu logicznego zwracająca informacje o tym czy kolcek jest zniszczony
	void Destroy();// metoda typu pustego niszcząca klocek
	sf::Vector2f GetSize(); //metoda typu Vector2f zwracająca wielkość kolcka

private:
	bool destroyed = false; //zmienna typu logiczego przechowująca stan klocka (zniszczony lub nie)
};

