#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "Object.h"
#include <fstream>
#include <iostream>

const int howMuchItems = 4;//sta�a typu ca�kowitego przechowuj�ca ilo�� mo�liwych do kupienia przedmiot�w
class Shop: public Object
{
public:
	Shop();//kosntruktor bezargumentowy
	~Shop();//destruktor
	void SaveItems();//metoda typu pustego zapisuj�ca kupione przedmioty w pliku
	sf::RectangleShape shopItems[howMuchItems]; //tablica typu RectangleShape przechowuj�ca graficzn� reprezentacj� paletek w sklepie
	sf::Text shopItemNames[howMuchItems];//tablica typu Text przechowuj�ca podpis ka�dej paletki w sklepie
	sf::Sprite ItemsSprites[howMuchItems];//tablica typu Sprite przechowuj�ca grafik� ka�dej paletki w sklepie
	sf::RectangleShape blackRecktangles[howMuchItems];//tablica typu RectangleShape przechowuj�ca czarne t�o dla ka�dego zdj�cia paletki w sklepie

	int Update(sf::Vector2f mouse, sf::RenderWindow &window);//metoda typu ca�kowitego zarz�dzaj�ca sklepem z parametrami typu Vctro2f i RenderWindow
	void BuyPaddle(Paddle &paddle, int &amountOfCoins);//metoda typu pustego zajmuj�ca si� kupowanie paletek i przyjmuj�ca daw paramery typu Paddle i int przez referencje
	void IsButtonReleased(sf::Event event);//metoda typu pustego sprawdzaj�ca czy przycisk myszy zosta� zwolniony
	void DisableButton();//metoda typu pustego ustawiaj�ca zmienn� 'buttonReleased'
	void OpenDescriptions();//metoda typu pustego zajmuj�ca si� wczzytaniem opsi�w paletek z plik�w
	bool availableItems[howMuchItems];//tablica typu logicznego przechowuj�ca informacj� od dost�pnych ju� paletkach
	void GetSprites(sf::Sprite sprites[]);//metoda typu pustego pobieraj�ca grafiki paletek z pliku z tablic� typu Sprite jako parametr


private:
	bool StringToBool(std::string a);//metoda typu logicznego zmieniaj�ca otrzymay w parametrze ci�g znak�w na warto�� typu bool
	void OpenDescription(std::string path,int id);//metoda typu pustego kt�ra �aduje opis paletki o Id i �cie�ce pliku podanych w parametrze 
	void SetUpItemsPictures();//metoda typu pustego ustawiaj�ca grafiki paletek w sklepie
	void SetUpItemsTexts();//metoda typu pustego ustawiaj�ca podpisy paletek w sklepie
	void LoadAvailableItems();//metoda typu pustego kt�ra z pliku wczytuje dost�pne paletki
	float shopItemWidth = 230;;//zmienna typu zmiennoprzecinkowego reprezentuj�ca szeroko�� ka�dego zdj�cia paletek w sklepie
	float shopItemHeigth= 100;;//zmienna typu zmiennoprzecinkowego reprezentuj�ca wysoko�� ka�dego zdj�cia paletek w sklepie
	float blackRectangleWidth = shopItemWidth - 10;;//zmienna typu zmiennoprzecinkowego reprezentuj�ca szeroko�� czrnego kwadratu
	float blackRectangleHeigth = shopItemHeigth -10;//zmienna typu zmiennoprzecinkowego reprezentuj�ca wysoko�� czrnego kwadratu

	sf::Font font;//zmienna typu Font przechowuj�ca czci�k� dla Sklepu
	bool buttonReleased = true;//zmienna typu logicznego sprawdzaj�ca czy przycisk mysz zosta� zwolniony
	sf::Text descriptions[howMuchItems]; //tablica typu Text kt�ra przechowuje opisy przedmiot�w w sklepie
	std::fstream shopFile;// zmienna reprezentuj�ca plik z dost�pnymi przedmiotami ze sklepu
};



