#pragma once
#include "Object.h"
#include <iostream>
class Paddle: public Object
{
public:
	Paddle();//konstruktor bezargumentowy
	~Paddle()= default;//destruktor
	
	void Update();//metoda typu pustego zarz¹dzaj¹ca ruchami paletki
	void ChangeSize(int increase); //metoda typu pustego zmieniaj¹ca rozmiar paletki z parametrem typu ca³kowitego
	void ChangeControl();//metoda typu pustego zmieniaj¹ca ststem kontrolowania paletki
	void SetActive();//metoda typu pustego ustawiaj¹ca dan¹ paletkê jako aktywn¹
	void Deactive();//metoda typu pustego ustawiaj¹ca dan¹ paletkê jako nie aktywn¹
	bool IsActive();//metoda typu logicznego zwracaj¹ca wartoœæ mówi¹c¹ czy patka jest aktywna
	int GetId();//metoda typu ca³kowitego zwracaj¹ca Id paletki

	int GetPrice();//metoda typu ca³kowitego zwracaj¹ca cenê paletki
	void Reset();//metoda typu pustego przywracaj¹ca paletce wszysteki w³asnoœci domyœlne
protected:
	
	const float paddleWidth = 160.0f;//sta³a typu zmiennoprzecinkowego przechowuj¹ca szerokoœæ paletki
	const float paddleHeigth = 20.0f;//sta³a typu zmiennoprzecinkowego przechowuj¹ca wysokoœæ paletki
	const float paddleVelocity = 6.0f;//sta³a typu zmiennoprzecinkowego przechowuj¹ca szybkoœæ paletki
	sf::Vector2f velocity{ paddleVelocity, 0.0f }; //zmienna typu Vector2f przechowuj¹ca kierunek ruchu paletki
	int control = 1;//zmienna ca³kowita przechowuj¹ca informacjê o aktualnej wersji kontorli paletki
	bool active = true;// zmienna logiczna mówi¹ca czy paletka jest aktywna
	void NormalControl();//metoda typu pustego zmieniaj¹ca konrolowanie paletki na normalne
	void ReverseControl();//metoda typu pustego zmieniaj¹ca konrolowanie paletki na odwrucone
	int price = 0;//zmienna typu ca³kowitego przechowuj¹ca cenê paletki
	int id;//zmienna typu ca³kowitego przechowuj¹ca Id paletki

};



