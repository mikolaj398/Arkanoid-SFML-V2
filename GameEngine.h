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
	sf::RenderWindow window;//zmienna typu RenderWindow renderuj¹ca okno aplikacji
	void RunGame();// metoda typu pustego zarz¹dzaj¹ca ca³¹ gr¹
	
private:

	sf::Texture textures[22];// tablica zmiennych typu Texture przechowuj¹ca wszystkie tekstury z gry
	sf::Sprite sprites[22];// tablica zmiennych typu Sprite przechowuj¹ca wszystkie grafiki z gry

	enum GameState { MENU, GAME, SHOP, PADDLE_CHOOSER, LEVEL_MENAGER, LEVEL_COMPLETED, GAME_OVER, END };
	GameState state;//enum przechowuj¹cy informacjê o aktualnym stanie aplikacji

	std::fstream coinsFile;// zmienna typu fstream przechowuj¹ca iloœæ monet w pliku
	sf::Font font;// zmienna typu Font przechowuj¹ca czci¹kê menu

	LevelMenager level;// zmienna typy LevelMenager zarz¹daj¹ca zmian¹ i ³adowaniem poziomów
	PaddleChooser paddleChooser; // zmienna typy PaddleChooser zarz¹daj¹ca zmian¹ i ³adowaniem paletek
	Shop shop; // zmienna typy Shop zarz¹daj¹ca sklepem
	Coins coins; // zmienna typy Coins przechowuj¹ca informacje o w³asnoœciach monet

	Ball ball; // zmienna typy Coins przechowuj¹ca informacje o w³asnoœciach monet
	SuperBall superBall; // zmienna typy SuperBall przechowuj¹ca informacje o w³asnoœciach bonusu SuperBall

	int amountOfCoins = 0; //zmienna typu ca³kowitego przechowuj¹ca iloœæ monet w grze

	void Menu();//metoda typu pustego zarz¹daj¹ca menu
	void Game();//metoda typu pustego zarz¹dzaj¹ca gr¹
	void GameOver();//metoda typu pustego powiadamiaj¹ca o przegranej
	void LevelMenagerFun();//metoda typu pustego zarz¹dzaj¹ca wyborem poziomów
	void Shop();//metoda typu pustego zarz¹dzaj¹ca sklepem
	void PaddleChooser();//metoda typu pustego zarz¹dzaj¹ca menu wyboru paletek
	void SetMenuTexts(int howMuchTexts, sf::Text texts[]);//metoda typu pustego ustawiaj¹ca teksty w Menu 
	//przyjmuj¹ca parametr typu ca³kowitego mówi¹cy o iloœci tekstów oraz tablicê typu Text przechowuj¹c¹ te teksty

	void ColorMenuTexts(int howMuchTexts, sf::Text texts[],sf::Vector2f mouse);//metoda typu pustego ustawiaj¹ca kolor tekstów w Menu 
	//przyjmuj¹ca parametr typu ca³kowitego mówi¹cy o iloœci tekstów, tablicê typu Text przechowuj¹c¹ te teksty oraz pozycjê myszki

	void Save();//metoda typu pustego zapisuj¹ca postêp w grze wywo³ywana zawsze przed zamkniêciem

	void CheckMenuEvents(sf::Event event, sf::Text texts[], sf::Vector2f mouse);//metoda typu pustego
	                                              //sprawdzaj¹ca wydarzenia (klikniêcie myszy) w Menu

	void LoadSprites();//metoda typu pustego ³aduj¹ca grafiki z plików

	Paddle player; // zmienna typy Paddle przechowuj¹ca informacje o w³asnoœciach monet
	RedPaddle redPaddle; // zmienna typy RedPaddle przechowuj¹ca informacje o w³asnoœciach monet
	BluePaddle bluePaddle; // zmienna typy BluePaddle przechowuj¹ca informacje o w³asnoœciach monet
	YellowPaddle yellowPaddle; // zmienna typy YellowPaddle przechowuj¹ca informacje o w³asnoœciach monet
	GreenPaddle greenPaddle; // zmienna typy GreenPaddle przechowuj¹ca informacje o w³asnoœciach monet

	template <class T1, class T2> bool IsIntersecting(T1 &A, T2 &B);// metoda typu logicznego zwracaj¹ca prawdê
				  //je¿eli dwa dowolne obiekty, przekazywane jako parametr przez referencjê, nachodz¹ na siebie

	bool CheckGameOver(Ball &ball); //metoda typu logicznego sprawdzaj¹ca koniec gry z parametrem typu Ball przekazanym referencj¹

	bool Collisions(Paddle &paddle, Ball &ball);//metoda typu logicznego zajmuj¹ca siê kolizj¹ miêdzy paletk¹ a pi³k¹ 
	                                                 //z parametrami typu Paddle i Ball przekazanymi przez referencjê

	bool Collisions(Block &block, Ball &ball);//metoda typu logicznego zajmuj¹ca siê kolizj¹ miêdzy blokiem a pi³k¹ 
	                                                //z parametrami typu Block i Ball przekazanymi przez referencjê

	bool Collisions(Bonus &bonus, Paddle &paddle);//metoda typu logicznego zajmuj¹ca siê kolizj¹ miêdzy paletk¹ a bonusem 
	                                                    //z parametrami typu Paddle i bonus przekazanymi przez referencjê

	void LevelCompleted(); //metoda typu pustego wyœwietlajca komunika o ukoñczeniu poziomu
	Bonus SpawnBonus(float pos_X, float pos_Y,int id);//metoda typu Bonus pokazuj¹ca bonus 
	                   //z dwoma parametrami typu zmiennoprzecinkowego i jednym ca³kowitym

	void UseBonus(int id);//metoda typu pustego która wywo³uje akcje la ka¿dego z bonusów
	                      //przyjmuje jeden parametr typu ca³kowitego

	void RedPaddleSpecial();//metoda typu pustego wywo³uj¹ca specjaln¹ akcjê dla czerownej paletki
	void GreenPaddleSpecial();//metoda typu pustego wywo³uj¹ca specjaln¹ akcjê dla zielonej paletki
	void BluePaddleSpecial();//metoda typu pustego wywo³uj¹ca specjaln¹ akcjê dla niebieskiej paletki

	void UpdateAndRemoveBlocks(std::vector<Block> &blocks, std::vector<Bonus> &bonuses);//metoda typu pustego
	//która rysuje i sprawdza kolizje pi³ki z ka¿dym blokiem z dwoma tablicami wektorowymi przekazanymi przez referencjê
	void UpdateAndRemoveBonuses(std::vector<Bonus> &bonuses);//metoda typu pustego
	//która rysuje i sprawdza kolizje paletki z ka¿dym bonusem z tablic¹ wektorow¹ przekazan¹ przez referencjê jako parametr

	void SetUpGameOverTexts(int howMuchTexts, sf::Text texts[]);//metoda typu pustego ustawiaj¹ca teksty w komunikacie o przegranej 
	//przyjmuj¹ca parametr typu ca³kowitego mówi¹cy o iloœci tekstów oraz tablicê typu Text przechowuj¹c¹ te teksty
	void SetUpLevelCompletedTexts(sf::Text &levelText, sf::Text &continueText, sf::Text &menuText);//metoda typu pustego 
	//ustawiaj¹ca teksty w komunikacie o wygranej przyjmuj¹ca 3 parametry typu Text przekazanymi przez referencjê

	void CheckBuyingItems(sf::Vector2f mouse);//metoda typu pustego sprawdzaj¹ca kupno paletki w sklepie przyjmuj¹ca Vector2f jako parametr
	void ChoosePaddle(int paddleNumber);//metoda typu pustego sprawdzaj¹ca wybór paletek przyjmuj¹ca parametr typu ca³kowitego

	std::string coinsText;//zmienna typu string przechowuj¹ca infrmacjê o liczbie monet i s³u¿aca do ustawiania zmiennej typu Text

};


