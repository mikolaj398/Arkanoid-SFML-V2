#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "Object.h"
#include <fstream>
#include <iostream>

const int howMuchItems = 4;//sta³a typu ca³kowitego przechowuj¹ca iloœæ mo¿liwych do kupienia przedmiotów
class Shop: public Object
{
public:
	Shop();//kosntruktor bezargumentowy
	~Shop();//destruktor
	void SaveItems();//metoda typu pustego zapisuj¹ca kupione przedmioty w pliku
	sf::RectangleShape shopItems[howMuchItems]; //tablica typu RectangleShape przechowuj¹ca graficzn¹ reprezentacjê paletek w sklepie
	sf::Text shopItemNames[howMuchItems];//tablica typu Text przechowuj¹ca podpis ka¿dej paletki w sklepie
	sf::Sprite ItemsSprites[howMuchItems];//tablica typu Sprite przechowuj¹ca grafikê ka¿dej paletki w sklepie
	sf::RectangleShape blackRecktangles[howMuchItems];//tablica typu RectangleShape przechowuj¹ca czarne t³o dla ka¿dego zdjêcia paletki w sklepie

	int Update(sf::Vector2f mouse, sf::RenderWindow &window);//metoda typu ca³kowitego zarz¹dzaj¹ca sklepem z parametrami typu Vctro2f i RenderWindow
	void BuyPaddle(Paddle &paddle, int &amountOfCoins);//metoda typu pustego zajmuj¹ca siê kupowanie paletek i przyjmuj¹ca daw paramery typu Paddle i int przez referencje
	void IsButtonReleased(sf::Event event);//metoda typu pustego sprawdzaj¹ca czy przycisk myszy zosta³ zwolniony
	void DisableButton();//metoda typu pustego ustawiaj¹ca zmienn¹ 'buttonReleased'
	void OpenDescriptions();//metoda typu pustego zajmuj¹ca siê wczzytaniem opsiów paletek z plików
	bool availableItems[howMuchItems];//tablica typu logicznego przechowuj¹ca informacjê od dostêpnych ju¿ paletkach
	void GetSprites(sf::Sprite sprites[]);//metoda typu pustego pobieraj¹ca grafiki paletek z pliku z tablic¹ typu Sprite jako parametr


private:
	bool StringToBool(std::string a);//metoda typu logicznego zmieniaj¹ca otrzymay w parametrze ci¹g znaków na wartoœæ typu bool
	void OpenDescription(std::string path,int id);//metoda typu pustego która ³aduje opis paletki o Id i œcie¿ce pliku podanych w parametrze 
	void SetUpItemsPictures();//metoda typu pustego ustawiaj¹ca grafiki paletek w sklepie
	void SetUpItemsTexts();//metoda typu pustego ustawiaj¹ca podpisy paletek w sklepie
	void LoadAvailableItems();//metoda typu pustego która z pliku wczytuje dostêpne paletki
	float shopItemWidth = 230;;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca szerokoœæ ka¿dego zdjêcia paletek w sklepie
	float shopItemHeigth= 100;;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca wysokoœæ ka¿dego zdjêcia paletek w sklepie
	float blackRectangleWidth = shopItemWidth - 10;;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca szerokoœæ czrnego kwadratu
	float blackRectangleHeigth = shopItemHeigth -10;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca wysokoœæ czrnego kwadratu

	sf::Font font;//zmienna typu Font przechowuj¹ca czci¹kê dla Sklepu
	bool buttonReleased = true;//zmienna typu logicznego sprawdzaj¹ca czy przycisk mysz zosta³ zwolniony
	sf::Text descriptions[howMuchItems]; //tablica typu Text która przechowuje opisy przedmiotów w sklepie
	std::fstream shopFile;// zmienna reprezentuj¹ca plik z dostêpnymi przedmiotami ze sklepu
};



