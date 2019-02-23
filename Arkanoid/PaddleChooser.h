#pragma once
#include "Object.h"
#include "Paddle.h"
#include "RedPaddle.h"

const int howMuchPaddles = 5;//sta�a typu ca�kowitego m�wi�ca z ilu paletek mo�emy wybiera�
class PaddleChooser :public Object
{
public:
	PaddleChooser();//konstruktor bezargumentowy
	~PaddleChooser();//destruktor
	sf::RectangleShape paddlesPictures[howMuchPaddles];//tablica typu RectangleShape przechowuj�ca graficzn� reprezentacj� paletek w oknie aplikacji
	sf::Text paddlesNamesText[howMuchPaddles];//tablica typu Text przechowuj�ca podpis ka�dej paletki
	sf::Sprite paddlesSprites[howMuchPaddles];//tablica typu Sprite przechowuj�ca grafik� ka�dej paletki
	sf::RectangleShape blackRecktangles[howMuchPaddles];//tablica typu RectangleShape przechowuj�ca czarne t�o dla ka�dego zdj�cia paletki

	int Update(sf::Vector2f mouse); //metoda typu int zwracaj�ca id paletki kt�r� chcemy wybra� z parametrem typu Vector2f
	void IsButtonReleased(sf::Event event);//metoda typu pustego sprawdzaj�ca czy gra� pu�ci� przycisk myszy z parametrem typu Event
	void DisableButton();//metoda typu pustego ktora ustawia warto�� zmiennej 'buttonReleased'
	void SetNewPlayer(Paddle &oldPlayer, Paddle &newPlayer);//metoda typu pustego zamieniaj�ca paletki z dwoma parametrami typu Paddle przekazanymi przez referencj�
	void GetSprites(sf::Sprite sprites[]); //metoda typu pustego pobieraj�ca grafiki paletek z pliku z tablic� typu Sprite jako parametr

private:
	sf::Font font;//zmienna typu Font przechowuj�ca czcionk� dla Menu Wyboru Paletek
	bool buttonReleased = false;//zmienna typu logicznego s�u��ca do sprawdzania czy przycisk mysz zosta� zwolniony

	float pladdlesPicturesWidth = 230;//zmienna typu zmiennoprzecinkowego reprezentuj�ca wysoko�� ka�dego zdj�cia paletek
	float pladdlesPicturesHeigth= 100;//zmienna typu zmiennoprzecinkowego reprezentuj�ca szeroko�� ka�dego zdj�cia paletek
	float blackRectangleWidth = pladdlesPicturesWidth - 10;//zmienna typu zmiennoprzecinkowego reprezentuj�ca wysoko�� czarnego kwadratu 
	float blackRectangleHeigth = pladdlesPicturesHeigth - 10;//zmienna typu zmiennoprzecinkowego reprezentuj�ca wysoko�� ka�dego czarnego kwadratu 

	void SetPaddlesPictures();//metoda typu pustego ustawiaj�ca grafiki paletek
	void SetPaddlesTexts();//metoda typu pustego ustawiaj�ca podpisy paletek
};





