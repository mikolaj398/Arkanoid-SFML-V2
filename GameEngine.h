#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Object.h"
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "LevelMenager.h"
#include "Bonus.h"
#include "ExpandPaddle.h"
#include "ShortenPaddle.h"
#include "AccelerateBall.h"
#include "SlowBall.h"
#include "SuperBall.h"
#include "ReverseControl.h"
#include "Shop.h"
#include "Coins.h"
#include "PaddleChooser.h"
#include "RedPaddle.h"
#include "BluePaddle.h"
#include "YellowPaddle.h"
#include "GreenPaddle.h"

class GameEngine: public Object
{
public:
	GameEngine(); //konstruktor bezparametrowy
	sf::RenderWindow window;//zmienna typu RenderWindow renderuj�ca okno aplikacji
	void RunGame();// metoda typu pustego zarz�dzaj�ca ca�� gr�
	
private:

	sf::Texture textures[22];// tablica zmiennych typu Texture przechowuj�ca wszystkie tekstury z gry
	sf::Sprite sprites[22];// tablica zmiennych typu Sprite przechowuj�ca wszystkie grafiki z gry

	enum GameState { MENU, GAME, SHOP, PADDLE_CHOOSER, LEVEL_MENAGER, LEVEL_COMPLETED, GAME_OVER, END };
	GameState state;//enum przechowuj�cy informacj� o aktualnym stanie aplikacji

	std::fstream coinsFile;// zmienna typu fstream przechowuj�ca ilo�� monet w pliku
	sf::Font font;// zmienna typu Font przechowuj�ca czci�k� menu

	LevelMenager level;// zmienna typy LevelMenager zarz�daj�ca zmian� i �adowaniem poziom�w
	PaddleChooser paddleChooser; // zmienna typy PaddleChooser zarz�daj�ca zmian� i �adowaniem paletek
	Shop shop; // zmienna typy Shop zarz�daj�ca sklepem
	Coins coins; // zmienna typy Coins przechowuj�ca informacje o w�asno�ciach monet

	Ball ball; // zmienna typy Coins przechowuj�ca informacje o w�asno�ciach monet
	SuperBall superBall; // zmienna typy SuperBall przechowuj�ca informacje o w�asno�ciach bonusu SuperBall

	int amountOfCoins = 0; //zmienna typu ca�kowitego przechowuj�ca ilo�� monet w grze

	void Menu();//metoda typu pustego zarz�daj�ca menu
	void Game();//metoda typu pustego zarz�dzaj�ca gr�
	void GameOver();//metoda typu pustego powiadamiaj�ca o przegranej
	void LevelMenagerFun();//metoda typu pustego zarz�dzaj�ca wyborem poziom�w
	void Shop();//metoda typu pustego zarz�dzaj�ca sklepem
	void PaddleChooser();//metoda typu pustego zarz�dzaj�ca menu wyboru paletek
	void SetMenuTexts(int howMuchTexts, sf::Text texts[]);//metoda typu pustego ustawiaj�ca teksty w Menu 
	//przyjmuj�ca parametr typu ca�kowitego m�wi�cy o ilo�ci tekst�w oraz tablic� typu Text przechowuj�c� te teksty

	void ColorMenuTexts(int howMuchTexts, sf::Text texts[],sf::Vector2f mouse);//metoda typu pustego ustawiaj�ca kolor tekst�w w Menu 
	//przyjmuj�ca parametr typu ca�kowitego m�wi�cy o ilo�ci tekst�w, tablic� typu Text przechowuj�c� te teksty oraz pozycj� myszki

	void Save();//metoda typu pustego zapisuj�ca post�p w grze wywo�ywana zawsze przed zamkni�ciem

	void CheckMenuEvents(sf::Event event, sf::Text texts[], sf::Vector2f mouse);//metoda typu pustego
	                                              //sprawdzaj�ca wydarzenia (klikni�cie myszy) w Menu

	void LoadSprites();//metoda typu pustego �aduj�ca grafiki z plik�w

	Paddle player; // zmienna typy Paddle przechowuj�ca informacje o w�asno�ciach monet
	RedPaddle redPaddle; // zmienna typy RedPaddle przechowuj�ca informacje o w�asno�ciach monet
	BluePaddle bluePaddle; // zmienna typy BluePaddle przechowuj�ca informacje o w�asno�ciach monet
	YellowPaddle yellowPaddle; // zmienna typy YellowPaddle przechowuj�ca informacje o w�asno�ciach monet
	GreenPaddle greenPaddle; // zmienna typy GreenPaddle przechowuj�ca informacje o w�asno�ciach monet

	template <class T1, class T2> bool IsIntersecting(T1 &A, T2 &B);// metoda typu logicznego zwracaj�ca prawd�
				  //je�eli dwa dowolne obiekty, przekazywane jako parametr przez referencj�, nachodz� na siebie

	bool CheckGameOver(Ball &ball); //metoda typu logicznego sprawdzaj�ca koniec gry z parametrem typu Ball przekazanym referencj�

	bool Collisions(Paddle &paddle, Ball &ball);//metoda typu logicznego zajmuj�ca si� kolizj� mi�dzy paletk� a pi�k� 
	                                                 //z parametrami typu Paddle i Ball przekazanymi przez referencj�

	bool Collisions(Block &block, Ball &ball);//metoda typu logicznego zajmuj�ca si� kolizj� mi�dzy blokiem a pi�k� 
	                                                //z parametrami typu Block i Ball przekazanymi przez referencj�

	bool Collisions(Bonus &bonus, Paddle &paddle);//metoda typu logicznego zajmuj�ca si� kolizj� mi�dzy paletk� a bonusem 
	                                                    //z parametrami typu Paddle i bonus przekazanymi przez referencj�

	void LevelCompleted(); //metoda typu pustego wy�wietlajca komunika o uko�czeniu poziomu
	Bonus SpawnBonus(float pos_X, float pos_Y,int id);//metoda typu Bonus pokazuj�ca bonus 
	                   //z dwoma parametrami typu zmiennoprzecinkowego i jednym ca�kowitym

	void UseBonus(int id);//metoda typu pustego kt�ra wywo�uje akcje la ka�dego z bonus�w
	                      //przyjmuje jeden parametr typu ca�kowitego

	void RedPaddleSpecial();//metoda typu pustego wywo�uj�ca specjaln� akcj� dla czerownej paletki
	void GreenPaddleSpecial();//metoda typu pustego wywo�uj�ca specjaln� akcj� dla zielonej paletki
	void BluePaddleSpecial();//metoda typu pustego wywo�uj�ca specjaln� akcj� dla niebieskiej paletki

	void UpdateAndRemoveBlocks(std::vector<Block> &blocks, std::vector<Bonus> &bonuses);//metoda typu pustego
	//kt�ra rysuje i sprawdza kolizje pi�ki z ka�dym blokiem z dwoma tablicami wektorowymi przekazanymi przez referencj�
	void UpdateAndRemoveBonuses(std::vector<Bonus> &bonuses);//metoda typu pustego
	//kt�ra rysuje i sprawdza kolizje paletki z ka�dym bonusem z tablic� wektorow� przekazan� przez referencj� jako parametr

	void SetUpGameOverTexts(int howMuchTexts, sf::Text texts[]);//metoda typu pustego ustawiaj�ca teksty w komunikacie o przegranej 
	//przyjmuj�ca parametr typu ca�kowitego m�wi�cy o ilo�ci tekst�w oraz tablic� typu Text przechowuj�c� te teksty
	void SetUpLevelCompletedTexts(sf::Text &levelText, sf::Text &continueText, sf::Text &menuText);//metoda typu pustego 
	//ustawiaj�ca teksty w komunikacie o wygranej przyjmuj�ca 3 parametry typu Text przekazanymi przez referencj�

	void CheckBuyingItems(sf::Vector2f mouse);//metoda typu pustego sprawdzaj�ca kupno paletki w sklepie przyjmuj�ca Vector2f jako parametr
	void ChoosePaddle(int paddleNumber);//metoda typu pustego sprawdzaj�ca wyb�r paletek przyjmuj�ca parametr typu ca�kowitego

	std::string coinsText;//zmienna typu string przechowuj�ca infrmacj� o liczbie monet i s�u�aca do ustawiania zmiennej typu Text

};


