#pragma once
#include "Bonus.h"
class Coins : public Bonus
{
public:
	Coins(int pos_X, int pos_Y, sf::Sprite sprite1);//konstruktor który przyjmuje dwie wartoœci tylu ca³kowitego 
												    //oraz grafikê bonusu

	Coins(); //konstrukor bezargumentowy
	~Coins();//destruktor

	sf::Text ShowCoinsInGame(int amount); //metoda typu Text pokazuj¹ca iloœæ monet w grze 
	       //przyjmuj¹ca parametr typu ca³kowitego który reprezentuje wartoœc do pokazania
	sf::Text ShowCoinsInShop(int amount); //metoda typu Text pokazuj¹ca iloœæ monet w sklepie 
	       //przyjmuj¹ca parametr typu ca³kowitego który reprezentuje wartoœc do pokazania
	
private:
	sf::Text gameCoinsText;//zmienna typu Text przechowuj¹ca informacje o tekscie wyœwietalj¹cym monety w grze
	sf::Text shopConisText;//zmienna typu Text przechowuj¹ca informacje o tekscie wyœwietalj¹cym monety w sklepie
	std::string ToString(int integer);// metoda typu String zmieniaj¹ca typ ca³kowity dostarczany prametrem na tekst
	sf::Font font; // zmienna przechowuj¹ca czcionkê dla 'gameCoinsText' i 'shopConisText'

	void SetGameCoinsText();//metoda typu pustego ustawiaj¹ca tekst o monetach wyœwietlanych w sklepie
	void SetShopCoinsText();//metoda typu pustego ustawiaj¹ca tekst o monetach wyœwietlanych w grze

	
};





