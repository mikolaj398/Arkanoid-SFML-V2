#include "LevelMenager.h"
#include <iostream>

LevelMenager::LevelMenager()
{	
	if (!font.loadFromFile("Fonts\\Gameplay.ttf"))
		return;

	SetUpLevelPictures();
	SetUpLevelTexts();
	LoadAvailableLevels();	
}
void LevelMenager::GetSprites(sf::Sprite sprites[])
{
	for (int i = 0; i < howMuchLevels; i++)
	{
		levelsSprites[i] = sprites[i + 12];
		levelsSprites[i].setOrigin(445,175);
		levelsSprites[i].setPosition(levelsPictures[i].getPosition().x, levelsPictures[i].getPosition().y);
		levelsSprites[i].setScale(0.2f, 0.4f);
	}
	levelsSprites[0].setOrigin(335, 175);
	levelsSprites[2].setOrigin(335, 175);
	levelsSprites[6].setOrigin(390, 175);
}
void LevelMenager::SetUpLevelPictures()
{
	for (int i = 0; i < howMuchLevels; i++)
	{
		if (i<5)
			levelsPictures[i].setPosition(140 + (i * 250), 150);

		else
			levelsPictures[i].setPosition(140 + ((i - 5) * 250), windowHeigth - 250);

		levelsPictures[i].setFillColor(sf::Color::Cyan);
		levelsPictures[i].setSize({ levelsPicturesSize	,levelsPicturesSize });
		levelsPictures[i].setOrigin(levelsPicturesSize / 2.0f, levelsPicturesSize / 2.0f);

		blackRecktangles[i].setOrigin(this->blackRectangleWidth / 2.0f, this->blackRectangleHeigth / 2.0f);
		blackRecktangles[i].setPosition(levelsSprites[i].getPosition().x, levelsSprites[i].getPosition().y);
		blackRecktangles[i].setSize({ this->blackRectangleWidth,this->blackRectangleHeigth });
		blackRecktangles[i].setFillColor(sf::Color::Yellow);
	}
}
void LevelMenager::SetUpLevelTexts()
{
	std::string levelNumbers[howMuchLevels] = { "Level 1","Level 2","Level 3","Level 4","Level 5","Level 6","Level 7","Level 8","Level 9","Level 10" };
	for (int i = 0; i < howMuchLevels; i++)
	{
		if (i<5)
			levelNumber[i].setPosition(45 + (i * 250), 265);
		else
			levelNumber[i].setPosition(45 + ((i - 5) * 250), windowHeigth - 130);

		levelNumber[i].setString(levelNumbers[i]);
		levelNumber[i].setFont(font);
		levelNumber[i].setCharacterSize(40);

	}
}
void LevelMenager::LoadAvailableLevels()
{
	levelMenagerFile.open("Files\\levelMenager.txt");
	std::string pom; //zmienna pomocnicz do kt�rej zapisujemy pojedy�cze wiersze
	int i = 0;
	while (levelMenagerFile.eof() != true) //przechodzimy przez ca�y plik
	{
		std::getline(levelMenagerFile, pom); //zczytujemy lini�
		availableLevels[i] = StringToBool(pom); //zmieniamy warot�� na bool i wpisujemy j� do tablicy
		i++;
	}
	availableLevels[0] = true; //pierwszy poziom powinien by� zawsze dost�pny
}

void LevelMenager::SaveLevels()
{
	levelMenagerFile.clear(); //czy�cimy plik z dost�pnymi poziomami
	levelMenagerFile.seekp(std::ios::beg); //ustawiamu kursor na pocz�tek
	for (int i = 0; i < howMuchLevels; i++)
	{
		levelMenagerFile << availableLevels[i] << std::endl; //zapisujemy tabele do pilku
	}
	levelMenagerFile.close();
}
bool LevelMenager::StringToBool(std::string a)
{
	if (a == "0") return false;
	return true;
}

void LevelMenager::Update(sf::Vector2f mouse)
{
	for (int i = 0; i < 10; i++)

			if ((levelsPictures[i].getGlobalBounds().contains(mouse))&&(availableLevels[i]==true)) 
			{
				levelsPictures[i].setFillColor(sf::Color::Magenta); //je�li myszka znajduje si� w tek�cie to zmienia jego kolor
				if (buttonReleased==true) //je�li przycisk myszy zost�� zwolniony to wybrrali�my poziom i zostajem zmieniona warot�� enuma 'lvl'
				{                         //oraz mo�emy ju� przchodzi� do gry
					lvl = (GameLevels)(i);
					changeForGameState = true;
				}
			}
			else levelsPictures[i].setFillColor(sf::Color::Cyan);
}
void LevelMenager::IsButtonReleased(sf::Event event)
{
	if ((event.type == sf::Event::MouseButtonPressed) && (event.key.code == sf::Mouse::Left)) this->buttonReleased = true;
}
void LevelMenager::DisableButton()
{
	this->buttonReleased = false;
}

void LevelMenager::LoadLevel(Ball &ball, Paddle &paddle, std::vector<Block> &blocks)
{
	
	ball.SetPosition(windowWidth / 2, windowHeigth / 2); //ustawiamy pi�k� na �rodku ekranu
	paddle.SetPosition(windowWidth / 2, windowHeigth - 60); // ustawiamy paletk� na �rodku dolnej kraw�dzi

	switch (lvl) //w zale�no�ci od tego w kt�ry poziom chcemy zagra� wywo�ujemy odpowiedni� funkcj� i przekazujemy jej dalej tablic� z blokami aby j� odpowiednio uzupe�ni�a
	{
	case LevelMenager::LEVEL_1: LoadLevel_1(blocks); break;
	case LevelMenager::LEVEL_2: LoadLevel_2(blocks); break;
	case LevelMenager::LEVEL_3: LoadLevel_3(blocks); break;
	case LevelMenager::LEVEL_4: LoadLevel_4(blocks); break;
	case LevelMenager::LEVEL_5: LoadLevel_5(blocks); break;
	case LevelMenager::LEVEL_6: LoadLevel_6(blocks); break;
	case LevelMenager::LEVEL_7: LoadLevel_7(blocks); break;
	case LevelMenager::LEVEL_8: LoadLevel_8(blocks); break;
	case LevelMenager::LEVEL_9: LoadLevel_9(blocks); break;
	case LevelMenager::LEVEL_10: LoadLevel_10(blocks); break;
	default: break;
	}
}
void LevelMenager::LoadLevel_1(std::vector<Block> &blocks)
{
	int levelSetUp[howMuchBlocks][howMuchBlocks] = { 1,1,1,1,1,1,0,0, //1 - dodajemy blok
												     1,1,0,0,1,1,0,0, //0 - nie doadjemy bloku
													 1,1,0,0,1,1,0,0,
													 1,1,1,1,1,1,0,0,
													 1,1,0,0,0,0,0,0,
													 1,1,0,0,0,0,0,0,
													 1,1,0,0,0,0,0,0,
													 1,1,0,0,0,0,0,0};

	SetBlocks(levelSetUp, blocks, howMuchBlocks, howMuchBlocks); //funkcja kt�ra uzupe�nia wektorow� tablic� blok�w wed�ug powy�szej dwuwymiarowej tablicy 
}
void LevelMenager::LoadLevel_2(std::vector<Block> &blocks)
{
	int levelSetUp[howMuchBlocks][howMuchBlocks] = { 1,1,0,0,0,0,1,1,
													 1,1,0,0,0,0,1,1,
													 1,1,0,0,0,0,1,1,
													 1,1,0,1,1,0,1,1,
													 1,1,1,0,0,1,1,1,
													 1,1,1,0,0,1,1,1,
													 1,1,0,0,0,0,1,1,
													 0,0,0,0,0,0,0,0};

	SetBlocks(levelSetUp, blocks, howMuchBlocks, howMuchBlocks);
}
void LevelMenager::LoadLevel_3(std::vector<Block> &blocks)
{
	int levelSetUp[howMuchBlocks][howMuchBlocks] = { 1,1,1,1,1,1,0,0,
													 1,1,0,0,1,1,0,0,
													 1,1,0,0,1,1,0,0,
													 1,1,1,1,1,1,0,0,
													 1,1,1,0,0,0,0,0,
													 1,1,0,1,0,0,0,0,
													 1,1,0,0,1,0,0,0,
													 1,1,0,0,0,1,0,0 };

	SetBlocks(levelSetUp, blocks, howMuchBlocks, howMuchBlocks);
}
void LevelMenager::LoadLevel_4(std::vector<Block> &blocks)
{
	int levelSetUp[howMuchBlocks][howMuchBlocks] = { 0,0,0,1,1,0,0,0,
													 0,0,1,1,1,1,0,0,
													 0,1,0,1,1,0,1,0,
													 1,1,1,1,1,1,1,1,
													 0,1,0,1,1,0,1,0,
													 0,0,1,1,1,1,0,0,
													 0,0,0,1,1,0,0,0,
													 0,0,0,0,0,0,0,0};

	SetBlocks(levelSetUp, blocks, howMuchBlocks, howMuchBlocks);
}
void LevelMenager::LoadLevel_5(std::vector<Block> &blocks)
{
	int levelSetUp[howMuchBlocks][howMuchBlocks] = { 1,1,1,1,1,1,1,1,
													 1,0,0,0,0,0,1,1,
													 1,0,0,0,0,1,0,1,
													 1,0,0,1,1,0,0,1,
													 1,0,1,0,0,0,0,1,
													 1,1,0,0,0,0,0,1,
													 1,1,1,1,1,1,1,1,
													 0,0,0,0,0,0,0,0 };

	SetBlocks(levelSetUp, blocks, howMuchBlocks, howMuchBlocks);
}
void LevelMenager::LoadLevel_6(std::vector<Block> &blocks)
{
	int levelSetUp[howMuchBlocks][howMuchBlocks] = { 1,0,1,0,1,0,1,0,
													 0,1,0,1,0,1,0,1,
													 1,0,1,0,1,0,1,0,
													 0,1,0,1,0,1,0,1,
													 1,0,1,0,1,0,1,0,
													 0,1,0,1,0,1,0,1,
													 1,0,1,0,1,0,1,0,
													 0,0,0,0,0,0,0,0};

	SetBlocks(levelSetUp, blocks, howMuchBlocks, howMuchBlocks);
}
void LevelMenager::LoadLevel_7(std::vector<Block> &blocks)
{
	int levelSetUp[howMuchBlocks][howMuchBlocks] = { 1,0,0,1,0,0,1,0,
													 0,1,0,1,0,1,0,0,
													 0,0,1,1,1,0,0,0,
													 1,1,1,1,1,1,1,0,
													 0,0,1,1,1,0,0,0,
													 0,1,0,1,0,1,0,0,
													 1,0,0,1,0,0,1,0,
													 0,0,0,0,0,0,0,0 };

	SetBlocks(levelSetUp, blocks, howMuchBlocks, howMuchBlocks);
}
void LevelMenager::LoadLevel_8(std::vector<Block> &blocks)
{
	int levelSetUp[howMuchBlocks][howMuchBlocks] = { 1,1,1,0,0,1,1,1,
													 1,1,1,0,0,1,1,1,
													 1,1,1,0,0,1,1,1,
													 0,0,0,1,1,0,0,0,
													 0,0,0,1,1,0,0,0,
													 1,0,0,0,0,0,0,1,
													 0,1,1,1,1,1,1,0,
													 0,0,0,0,0,0,0,0 };

	SetBlocks(levelSetUp, blocks, howMuchBlocks, howMuchBlocks);
}
void LevelMenager::LoadLevel_9(std::vector<Block> &blocks)
{
	int levelSetUp[howMuchBlocks][howMuchBlocks] = { 1,1,1,1,1,1,1,1,
													 1,1,0,0,0,0,1,1,
													 1,1,1,1,1,1,1,1,
													 1,1,0,0,0,0,1,1,
													 1,1,1,1,1,1,1,1,
													 1,1,0,0,0,0,1,1,
													 1,1,1,1,1,1,1,1,
													 0,0,0,0,0,0,0,0 };

	SetBlocks(levelSetUp, blocks, howMuchBlocks, howMuchBlocks);
}
void LevelMenager::LoadLevel_10(std::vector<Block> &blocks)
{
	int levelSetUp[howMuchBlocks][howMuchBlocks] = { 1,1,1,1,1,1,1,1,
												  	 1,1,1,1,1,1,1,1,
											 		 1,1,1,1,1,1,1,1,
													 1,1,1,1,1,1,1,1,
													 1,1,1,1,1,1,1,1,
													 1,1,1,1,1,1,1,1,
													 1,1,1,1,1,1,1,1,
													 0,0,0,0,0,0,0,0 };

	SetBlocks(levelSetUp, blocks, howMuchBlocks, howMuchBlocks);
}

void LevelMenager::SetBlocks(int level[howMuchBlocks][howMuchBlocks], std::vector<Block> &blocks, unsigned int blX, unsigned int blY)
{
	for (int i = 0; i < blX; i++)
		for (int j = 0; j < blY; j++)
			if (level[i][j] == 1) blocks.emplace_back(150 + ((j + 1) * 110), 20 + ((i + 1) * 50), 100, 30); //dodajemy do tablicy wektorowej bloki na odpowiedniej
																											//pozycji wed�ug wys�anej tablicy dwuwymiarowej
}
void LevelMenager::ChangeToNextLevel()
{
	//zmieniamy warto�� enum'a 'lvl' na nast�pn�
	lvl = static_cast<GameLevels>(lvl + 1);
}
