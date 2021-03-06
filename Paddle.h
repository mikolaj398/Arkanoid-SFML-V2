#pragma once
#include "Object.h"
#include <iostream>
class Paddle: public Object
{
public:
	Paddle();//konstruktor bezargumentowy
	~Paddle()= default;//destruktor
	
	void Update();//metoda typu pustego zarządzająca ruchami paletki
	void ChangeSize(int increase); //metoda typu pustego zmieniająca rozmiar paletki z parametrem typu całkowitego
	void ChangeControl();//metoda typu pustego zmieniająca ststem kontrolowania paletki
	void SetActive();//metoda typu pustego ustawiająca daną paletkę jako aktywną
	void Deactive();//metoda typu pustego ustawiająca daną paletkę jako nie aktywną
	bool IsActive();//metoda typu logicznego zwracająca wartość mówiącą czy patka jest aktywna
	int GetId();//metoda typu całkowitego zwracająca Id paletki

	int GetPrice();//metoda typu całkowitego zwracająca cenę paletki
	void Reset();//metoda typu pustego przywracająca paletce wszysteki własności domyślne
protected:
	
	const float paddleWidth = 160.0f;//stała typu zmiennoprzecinkowego przechowująca szerokość paletki
	const float paddleHeigth = 20.0f;//stała typu zmiennoprzecinkowego przechowująca wysokość paletki
	const float paddleVelocity = 6.0f;//stała typu zmiennoprzecinkowego przechowująca szybkość paletki
	sf::Vector2f velocity{ paddleVelocity, 0.0f }; //zmienna typu Vector2f przechowująca kierunek ruchu paletki
	int control = 1;//zmienna całkowita przechowująca informację o aktualnej wersji kontorli paletki
	bool active = true;// zmienna logiczna mówiąca czy paletka jest aktywna
	void NormalControl();//metoda typu pustego zmieniająca konrolowanie paletki na normalne
	void ReverseControl();//metoda typu pustego zmieniająca konrolowanie paletki na odwrucone
	int price = 0;//zmienna typu całkowitego przechowująca cenę paletki
	int id;//zmienna typu całkowitego przechowująca Id paletki

};



