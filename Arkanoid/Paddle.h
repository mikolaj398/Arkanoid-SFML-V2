#pragma once
#include "Object.h"
#include <iostream>
class Paddle: public Object
{
public:
	Paddle();//konstruktor bezargumentowy
	~Paddle()= default;//destruktor
	
	void Update();//metoda typu pustego zarz�dzaj�ca ruchami paletki
	void ChangeSize(int increase); //metoda typu pustego zmieniaj�ca rozmiar paletki z parametrem typu ca�kowitego
	void ChangeControl();//metoda typu pustego zmieniaj�ca ststem kontrolowania paletki
	void SetActive();//metoda typu pustego ustawiaj�ca dan� paletk� jako aktywn�
	void Deactive();//metoda typu pustego ustawiaj�ca dan� paletk� jako nie aktywn�
	bool IsActive();//metoda typu logicznego zwracaj�ca warto�� m�wi�c� czy patka jest aktywna
	int GetId();//metoda typu ca�kowitego zwracaj�ca Id paletki

	int GetPrice();//metoda typu ca�kowitego zwracaj�ca cen� paletki
	void Reset();//metoda typu pustego przywracaj�ca paletce wszysteki w�asno�ci domy�lne
protected:
	
	const float paddleWidth = 160.0f;//sta�a typu zmiennoprzecinkowego przechowuj�ca szeroko�� paletki
	const float paddleHeigth = 20.0f;//sta�a typu zmiennoprzecinkowego przechowuj�ca wysoko�� paletki
	const float paddleVelocity = 6.0f;//sta�a typu zmiennoprzecinkowego przechowuj�ca szybko�� paletki
	sf::Vector2f velocity{ paddleVelocity, 0.0f }; //zmienna typu Vector2f przechowuj�ca kierunek ruchu paletki
	int control = 1;//zmienna ca�kowita przechowuj�ca informacj� o aktualnej wersji kontorli paletki
	bool active = true;// zmienna logiczna m�wi�ca czy paletka jest aktywna
	void NormalControl();//metoda typu pustego zmieniaj�ca konrolowanie paletki na normalne
	void ReverseControl();//metoda typu pustego zmieniaj�ca konrolowanie paletki na odwrucone
	int price = 0;//zmienna typu ca�kowitego przechowuj�ca cen� paletki
	int id;//zmienna typu ca�kowitego przechowuj�ca Id paletki

};



