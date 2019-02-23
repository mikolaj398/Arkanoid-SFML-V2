#pragma once

#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "Object.h"
#include "RedPaddle.h"
#include <fstream>

const int howMuchBlocks = 8; //sta³a typu ca³kowitego przechowuj¹ca iloœæ bloków w wierszu i kolumnie
const int howMuchLevels = 10;//sta³a typu ca³kowitego przechowuj¹ca iloœæ poziomów
class LevelMenager: public Object
{
public:
	LevelMenager();//konstruktor bezargumentowy
	
	sf::RectangleShape levelsPictures[howMuchLevels];//tablica typu RectangleShape przechowuj¹ca graficzn¹ reprezentacjê pozomów w oknie aplikacji
	sf::Text levelNumber[howMuchLevels];//tablica typu Text przechowuj¹ca podpis ka¿dego poziomu
	sf::Sprite levelsSprites[howMuchLevels];//tablica typu Sprite przechowuj¹ca grafikê ka¿dego poziomu
	sf::RectangleShape blackRecktangles[howMuchLevels];//tablica typu RectangleShape przechowuj¹ca czarne t³o dla ka¿dego zdjêcia poziomu

	void SaveLevels();//metoda typu pustego zapisauj¹ca ukoñczone poziomy do pliku
	void Update(sf::Vector2f mouse);//metoda typu pustego
	void LoadLevel(Ball &ball, Paddle &paddle, std::vector<Block> &blocks);//metoda typu pustego
	void ChangeToNextLevel();//metoda typu pustego zmieniaj¹ca poziom na nastêpny
	void IsButtonReleased(sf::Event event);//metoda typu pustego sprawdzaj¹ca czy przycisk myszy zosta³ zwolniony
	void DisableButton();//metoda typu pustego ustawiaj¹ca zmienn¹ 'buttonReleased'

	enum GameLevels { LEVEL_1, LEVEL_2, LEVEL_3, LEVEL_4, LEVEL_5, LEVEL_6, LEVEL_7, LEVEL_8, LEVEL_9, LEVEL_10, };
	GameLevels lvl;//enum sprawdzaj¹cy który poziom trzeba teraz za³adowaæ

	bool availableLevels[howMuchLevels];//talica zmiennych logicznych przechowuj¹ca dostêpne poziomy ³adowane z pliku
	bool changeForGameState = false;// zmienna logiczna sprawdzaj¹ca czy poprawnie zosta³ za³adowany poziom do wczytania
	void GetSprites(sf::Sprite sprites[]);//metoda typu pustego pobieraj¹ca grafiki poziomów z pliku z tablic¹ typu Sprite jako parametr

private:
	bool StringToBool(std::string a); //metoda typu logicznego zmieniaj¹ca tekst typu string przekazywany jak parametr na wartoœæ logiczn¹
	std::fstream levelMenagerFile;//zmienna reprezentuj¹ca plik z dostêpneymimi poziomami
	float levelsPicturesSize = 200;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca rozmiar ka¿dej grafiki poziomów
	sf::Font font;//zmienna typu Font przechowuj¹ca czcionkê dla tekstów w Menu wyboru poziomów

	float levelsPicturesWidth= 230;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca szerokoœæ ka¿dego zdjêcia poziomów
	float levelsPicturesHeigth = 100;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca wysokoœæ ka¿dego zdjêcia poziomów
	float blackRectangleWidth = levelsPicturesWidth - 10;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca szerokoœæ czrnego kwadratu
	float blackRectangleHeigth = levelsPicturesHeigth - 10;//zmienna typu zmiennoprzecinkowego reprezentuj¹ca wysokoœæ czrnego kwadratu
	void LoadLevel_1(std::vector<Block> &blocks);//metoda typu pustego ³aduj¹ca 1 poziom z tablic¹ wektorow¹ przekazan¹ przez referencje jako parametr
	void LoadLevel_2(std::vector<Block> &blocks);//metoda typu pustego ³aduj¹ca 2 poziom z tablic¹ wektorow¹ przekazan¹ przez referencje jako parametr
	void LoadLevel_3(std::vector<Block> &blocks);//metoda typu pustego ³aduj¹ca 3 poziom z tablic¹ wektorow¹ przekazan¹ przez referencje jako parametr
	void LoadLevel_4(std::vector<Block> &blocks);//metoda typu pustego ³aduj¹ca 4 poziom z tablic¹ wektorow¹ przekazan¹ przez referencje jako parametr
	void LoadLevel_5(std::vector<Block> &blocks);//metoda typu pustego ³aduj¹ca 5 poziom z tablic¹ wektorow¹ przekazan¹ przez referencje jako parametr
	void LoadLevel_6(std::vector<Block> &blocks);//metoda typu pustego ³aduj¹ca 6 poziom z tablic¹ wektorow¹ przekazan¹ przez referencje jako parametr
	void LoadLevel_7(std::vector<Block> &blocks);//metoda typu pustego ³aduj¹ca 7 poziom z tablic¹ wektorow¹ przekazan¹ przez referencje jako parametr
	void LoadLevel_8(std::vector<Block> &blocks);//metoda typu pustego ³aduj¹ca 8 poziom z tablic¹ wektorow¹ przekazan¹ przez referencje jako parametr
	void LoadLevel_9(std::vector<Block> &blocks);//metoda typu pustego ³aduj¹ca 9 poziom z tablic¹ wektorow¹ przekazan¹ przez referencje jako parametr
	void LoadLevel_10(std::vector<Block> &blocks);//metoda typu pustego ³aduj¹ca 10 poziom z tablic¹ wektorow¹ przekazan¹ przez referencje jako parametr

	void SetBlocks(int level[howMuchBlocks][howMuchBlocks], std::vector<Block> &blocks,  int blX,  int blY);//metoda typu pustego
	//ustawiaj¹ca bloki w tabeli wektorowej wed³ug poziomu który trzeba za³adowaæ z tablic¹ dwuwymiarow¹ typu ca³kowitego, tablic¹ wektorow¹
	//przekazan¹ przez referencjê i dwoma wartoœciami typu ca³kowitego jako parametry
	
	void SetUpLevelPictures();//metoda typu pustego ustawiaj¹ca grafiki poziomów
	void SetUpLevelTexts();//metoda typu pustego ustawiaj¹ca podpisy poziomów
	void LoadAvailableLevels();//metoda typu pustego ³aduj¹ca z pliku dostêpne poziomy
	bool buttonReleased = false; //zmienna typu logicznego sprawdzaj¹ca czy przycisk mysz zosta³ zwolniony
};

