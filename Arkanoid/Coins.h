#pragma once
#include "Bonus.h"
class Coins : public Bonus
{
public:
	Coins(int pos_X, int pos_Y, sf::Sprite sprite1);//konstruktor kt�ry przyjmuje dwie warto�ci tylu ca�kowitego 
												    //oraz grafik� bonusu

	Coins(); //konstrukor bezargumentowy
	~Coins();//destruktor

	sf::Text ShowCoinsInGame(int amount); //metoda typu Text pokazuj�ca ilo�� monet w grze 
	       //przyjmuj�ca parametr typu ca�kowitego kt�ry reprezentuje warto�c do pokazania
	sf::Text ShowCoinsInShop(int amount); //metoda typu Text pokazuj�ca ilo�� monet w sklepie 
	       //przyjmuj�ca parametr typu ca�kowitego kt�ry reprezentuje warto�c do pokazania
	
private:
	sf::Text gameCoinsText;//zmienna typu Text przechowuj�ca informacje o tekscie wy�wietalj�cym monety w grze
	sf::Text shopConisText;//zmienna typu Text przechowuj�ca informacje o tekscie wy�wietalj�cym monety w sklepie
	std::string ToString(int integer);// metoda typu String zmieniaj�ca typ ca�kowity dostarczany prametrem na tekst
	sf::Font font; // zmienna przechowuj�ca czcionk� dla 'gameCoinsText' i 'shopConisText'

	void SetGameCoinsText();//metoda typu pustego ustawiaj�ca tekst o monetach wy�wietlanych w sklepie
	void SetShopCoinsText();//metoda typu pustego ustawiaj�ca tekst o monetach wy�wietlanych w grze

	
};





