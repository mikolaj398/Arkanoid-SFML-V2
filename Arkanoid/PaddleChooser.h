#pragma once
#include "Object.h"
#include "Paddle.h"
#include "RedPaddle.h"

const int howMuchPaddles = 5;//sta³a typu ca³kowitego mówi¹ca z ilu paletek mo¿emy wybieraæ
class PaddleChooser :public Object
{
public:
	PaddleChooser();//konstruktor bezargumentowy
	~PaddleChooser();//destruktor
	sf::RectangleShape paddlesPictures[howMuchPaddles];//tablica typu RectangleShape przechowuj¹ca graficzn¹ reprezentacjê paletek w oknie aplikacji
	sf::Text paddlesNamesText[howMuchPaddles];//tablica typu Text przechowuj¹ca podpis ka¿dej paletki
	sf::Sprite paddlesSprites[howMuchPaddles];//tablica typu Sprite przechowuj¹ca grafikê ka¿dej paletki
	sf::RectangleShape blackRecktangles[howMuchPaddles];//tablica typu RectangleShape przechowuj¹ca czarne t³o dla ka¿dego zdjêcia paletki

	int Update(sf::Vector2f mouse); //metoda typu int zwracaj¹ca id paletki któr¹ chcemy wybraæ z parametrem typu Vector2f
	void IsButtonReleased(sf::Event event);//metoda typu pustego sprawdzaj¹ca czy graæ puœci³ przycisk myszy z parametrem typu Event
	void DisableButton();//metoda typu pustego ktora ustawia wartoœæ zmiennej 'buttonReleased'
	void SetNewPlayer(Paddle &oldPlayer, Paddle &newPlayer);//metoda typu pustego zamieniaj¹ca paletki z dwoma parametrami typu Paddle przekazanymi przez referencjê
	void GetSprites(sf::Sprite sprites[]); //metoda typu pustego pobieraj¹ca grafiki paletek z pliku z tablic¹ typu Sprite jako parametr

private:
	sf::Font font;//zmienna typu Font przechowuj¹ca czcionkê dla Menu Wyboru Paletek
	bool buttonReleased = false;//zmienna typu logicznego s³u¿¹ca do sprawdzania czy przycisk mysz zosta³ zwolniony

	float pladdlesPicturesWidth = 230;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca wysokoœæ ka¿dego zdjêcia paletek
	float pladdlesPicturesHeigth= 100;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca szerokoœæ ka¿dego zdjêcia paletek
	float blackRectangleWidth = pladdlesPicturesWidth - 10;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca wysokoœæ czarnego kwadratu 
	float blackRectangleHeigth = pladdlesPicturesHeigth - 10;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca wysokoœæ ka¿dego czarnego kwadratu 

	void SetPaddlesPictures();//metoda typu pustego ustawiaj¹ca grafiki paletek
	void SetPaddlesTexts();//metoda typu pustego ustawiaj¹ca podpisy paletek
};





