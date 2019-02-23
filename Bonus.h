#pragma once
#include "Object.h"
class Bonus: public Object
{
public:
	Bonus()=default;//bezparametrowy konstruktor domyœlny
	Bonus(int pos_X, int pos_Y);//konstruktor przyjmuj¹cy dwa parametry typu ca³kowitego reprezentuj¹ce pozycjê pocz¹tkow¹
	~Bonus();//destruktor

	void MoveDown(); //metoda typu pustego poruszaj¹ca bonus prosto w dó³
	bool IsDestroyed();// metoda typu logicznego zwracaj¹ca stan bonusu
	void Destroy();// metoda typu pustego niszcz¹ca bonus
	int GetId();//metoda typu ca³kowitego zwracaj¹ca Id bonusu

protected:
	int id; //zmienna typu ca³kowitego przechowuj¹ca Id ró¿ne dla ka¿dego z bonusów i s³u¿¹ca do ich identyfikacji
	bool destroyed;//zmienna typu logicznego przechowuj¹ca stan bonusu (zniszczony lub nie)

private:
	float bonusWidth = 60.0f; //zmienna typu zmiennoprzecinkowego przechowuj¹ca szerokoœæ bonusu
	float bonusHeigth = 30.0f; //zmienna typu zmiennoprzecinkowego przechowuj¹ca wysokoœæ bonusu
	float bonusVelocity = 6.0f; //zmienna typu zmiennoprzecinkowego przechowuj¹ca szybkoœæ bonusu
	sf::Vector2f velocity{ 0.0f, bonusVelocity }; //zmienna typu Vector2f przechowuj¹ca kierunek poruszania si¹ bonusu
};

