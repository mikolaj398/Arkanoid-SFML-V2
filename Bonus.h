#pragma once
#include "Object.h"
class Bonus: public Object
{
public:
	Bonus()=default;//bezparametrowy konstruktor domy�lny
	Bonus(int pos_X, int pos_Y);//konstruktor przyjmuj�cy dwa parametry typu ca�kowitego reprezentuj�ce pozycj� pocz�tkow�
	~Bonus();//destruktor

	void MoveDown(); //metoda typu pustego poruszaj�ca bonus prosto w d�
	bool IsDestroyed();// metoda typu logicznego zwracaj�ca stan bonusu
	void Destroy();// metoda typu pustego niszcz�ca bonus
	int GetId();//metoda typu ca�kowitego zwracaj�ca Id bonusu

protected:
	int id; //zmienna typu ca�kowitego przechowuj�ca Id r�ne dla ka�dego z bonus�w i s�u��ca do ich identyfikacji
	bool destroyed;//zmienna typu logicznego przechowuj�ca stan bonusu (zniszczony lub nie)

private:
	float bonusWidth = 60.0f; //zmienna typu zmiennoprzecinkowego przechowuj�ca szeroko�� bonusu
	float bonusHeigth = 30.0f; //zmienna typu zmiennoprzecinkowego przechowuj�ca wysoko�� bonusu
	float bonusVelocity = 6.0f; //zmienna typu zmiennoprzecinkowego przechowuj�ca szybko�� bonusu
	sf::Vector2f velocity{ 0.0f, bonusVelocity }; //zmienna typu Vector2f przechowuj�ca kierunek poruszania si� bonusu
};

