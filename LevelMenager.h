#pragma once

#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "Object.h"
#include "RedPaddle.h"
#include <fstream>

const int howMuchBlocks = 8; //sta�a typu ca�kowitego przechowuj�ca ilo�� blok�w w wierszu i kolumnie
const int howMuchLevels = 10;//sta�a typu ca�kowitego przechowuj�ca ilo�� poziom�w
class LevelMenager: public Object
{
public:
	LevelMenager();//konstruktor bezargumentowy
	
	sf::RectangleShape levelsPictures[howMuchLevels];//tablica typu RectangleShape przechowuj�ca graficzn� reprezentacj� pozom�w w oknie aplikacji
	sf::Text levelNumber[howMuchLevels];//tablica typu Text przechowuj�ca podpis ka�dego poziomu
	sf::Sprite levelsSprites[howMuchLevels];//tablica typu Sprite przechowuj�ca grafik� ka�dego poziomu
	sf::RectangleShape blackRecktangles[howMuchLevels];//tablica typu RectangleShape przechowuj�ca czarne t�o dla ka�dego zdj�cia poziomu

	void SaveLevels();//metoda typu pustego zapisauj�ca uko�czone poziomy do pliku
	void Update(sf::Vector2f mouse);//metoda typu pustego
	void LoadLevel(Ball &ball, Paddle &paddle, std::vector<Block> &blocks);//metoda typu pustego
	void ChangeToNextLevel();//metoda typu pustego zmieniaj�ca poziom na nast�pny
	void IsButtonReleased(sf::Event event);//metoda typu pustego sprawdzaj�ca czy przycisk myszy zosta� zwolniony
	void DisableButton();//metoda typu pustego ustawiaj�ca zmienn� 'buttonReleased'

	enum GameLevels { LEVEL_1, LEVEL_2, LEVEL_3, LEVEL_4, LEVEL_5, LEVEL_6, LEVEL_7, LEVEL_8, LEVEL_9, LEVEL_10, };
	GameLevels lvl;//enum sprawdzaj�cy kt�ry poziom trzeba teraz za�adowa�

	bool availableLevels[howMuchLevels];//talica zmiennych logicznych przechowuj�ca dost�pne poziomy �adowane z pliku
	bool changeForGameState = false;// zmienna logiczna sprawdzaj�ca czy poprawnie zosta� za�adowany poziom do wczytania
	void GetSprites(sf::Sprite sprites[]);//metoda typu pustego pobieraj�ca grafiki poziom�w z pliku z tablic� typu Sprite jako parametr

private:
	bool StringToBool(std::string a); //metoda typu logicznego zmieniaj�ca tekst typu string przekazywany jak parametr na warto�� logiczn�
	std::fstream levelMenagerFile;//zmienna reprezentuj�ca plik z dost�pneymimi poziomami
	float levelsPicturesSize = 200;//zmienna typu zmiennoprzecinkowego reprezentuj�ca rozmiar ka�dej grafiki poziom�w
	sf::Font font;//zmienna typu Font przechowuj�ca czcionk� dla tekst�w w Menu wyboru poziom�w

	float levelsPicturesWidth= 230;//zmienna typu zmiennoprzecinkowego reprezentuj�ca szeroko�� ka�dego zdj�cia poziom�w
	float levelsPicturesHeigth = 100;//zmienna typu zmiennoprzecinkowego reprezentuj�ca wysoko�� ka�dego zdj�cia poziom�w
	float blackRectangleWidth = levelsPicturesWidth - 10;//zmienna typu zmiennoprzecinkowego reprezentuj�ca szeroko�� czrnego kwadratu
	float blackRectangleHeigth = levelsPicturesHeigth - 10;//zmienna typu zmiennoprzecinkowego reprezentuj�ca wysoko�� czrnego kwadratu
	void LoadLevel_1(std::vector<Block> &blocks);//metoda typu pustego �aduj�ca 1 poziom z tablic� wektorow� przekazan� przez referencje jako parametr
	void LoadLevel_2(std::vector<Block> &blocks);//metoda typu pustego �aduj�ca 2 poziom z tablic� wektorow� przekazan� przez referencje jako parametr
	void LoadLevel_3(std::vector<Block> &blocks);//metoda typu pustego �aduj�ca 3 poziom z tablic� wektorow� przekazan� przez referencje jako parametr
	void LoadLevel_4(std::vector<Block> &blocks);//metoda typu pustego �aduj�ca 4 poziom z tablic� wektorow� przekazan� przez referencje jako parametr
	void LoadLevel_5(std::vector<Block> &blocks);//metoda typu pustego �aduj�ca 5 poziom z tablic� wektorow� przekazan� przez referencje jako parametr
	void LoadLevel_6(std::vector<Block> &blocks);//metoda typu pustego �aduj�ca 6 poziom z tablic� wektorow� przekazan� przez referencje jako parametr
	void LoadLevel_7(std::vector<Block> &blocks);//metoda typu pustego �aduj�ca 7 poziom z tablic� wektorow� przekazan� przez referencje jako parametr
	void LoadLevel_8(std::vector<Block> &blocks);//metoda typu pustego �aduj�ca 8 poziom z tablic� wektorow� przekazan� przez referencje jako parametr
	void LoadLevel_9(std::vector<Block> &blocks);//metoda typu pustego �aduj�ca 9 poziom z tablic� wektorow� przekazan� przez referencje jako parametr
	void LoadLevel_10(std::vector<Block> &blocks);//metoda typu pustego �aduj�ca 10 poziom z tablic� wektorow� przekazan� przez referencje jako parametr

	void SetBlocks(int level[howMuchBlocks][howMuchBlocks], std::vector<Block> &blocks,  int blX,  int blY);//metoda typu pustego
	//ustawiaj�ca bloki w tabeli wektorowej wed�ug poziomu kt�ry trzeba za�adowa� z tablic� dwuwymiarow� typu ca�kowitego, tablic� wektorow�
	//przekazan� przez referencj� i dwoma warto�ciami typu ca�kowitego jako parametry
	
	void SetUpLevelPictures();//metoda typu pustego ustawiaj�ca grafiki poziom�w
	void SetUpLevelTexts();//metoda typu pustego ustawiaj�ca podpisy poziom�w
	void LoadAvailableLevels();//metoda typu pustego �aduj�ca z pliku dost�pne poziomy
	bool buttonReleased = false; //zmienna typu logicznego sprawdzaj�ca czy przycisk mysz zosta� zwolniony
};

