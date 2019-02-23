#include "Coins.h"



Coins::Coins(int pos_X, int pos_Y,sf::Sprite sprite1) : Bonus(pos_X, pos_Y)
{
	rect.setFillColor(sf::Color::White);
	id = 7;
	sprite = sprite1;
}
Coins::Coins()
{
	if (!font.loadFromFile("Fonts\\Gameplay.ttf")) return;
	SetGameCoinsText();
	SetShopCoinsText();
}

sf::Text Coins::ShowCoinsInGame(int amount)
{
	gameCoinsText.setString("Coins: " + ToString(amount)); //zamieniamy tekst na ten z aktualn¹ liczb¹ monet
	return gameCoinsText;
}
sf::Text Coins::ShowCoinsInShop(int amount)
{
	shopConisText.setString("Coins: " + ToString(amount)); //zamieniamy tekst na ten z aktualn¹ liczb¹ monet
	return shopConisText;
}
std::string Coins::ToString(int integer)
{
	std::string value="";
	while (integer > 0)
	{
		value = (char)(48 + (integer % 10))+value;
		integer /= 10;
	}
	return value;
}

void Coins::SetGameCoinsText()
{
	gameCoinsText.setFillColor(sf::Color::Cyan); //kolor tekstu
	gameCoinsText.setCharacterSize(20); //rozmiar czci¹ki
	gameCoinsText.setFont(font); //ustawienie wczeœniej wczytanej czæi¹ki
	gameCoinsText.setPosition(windowWidth - 170, 20); //ustawienie pozycji
}
void Coins::SetShopCoinsText()
{
	shopConisText.setFillColor(sf::Color::Yellow);//kolor tekstu
	shopConisText.setCharacterSize(60);//rozmiar czci¹ki
	shopConisText.setFont(font); //ustawienie wczeœniej wczytanej czæi¹ki
	shopConisText.setPosition((windowWidth / 3.0f) + 25, windowHeigth - 100);//ustawienie pozycji
}

Coins::~Coins()
{
}
