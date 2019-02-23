#include "GameEngine.h"

GameEngine::GameEngine()
{
	if (!font.loadFromFile("Fonts\\Games.ttf")) //�adujemy czcionk�
	{
		std::cout << "Font not found!" << std::endl;
		return;
	}

	coinsFile.open("Files\\amountOfCoins.txt"); //�adujemy ilo�� monet z pliku do zmiennej typu string
	if (coinsFile.good())
	{
		while (coinsFile.eof() != true)
		{
			std::getline(coinsFile, coinsText);
		}
	}
	else std::cout << "Coins File Error" << std::endl;
	amountOfCoins = std::stoi(coinsText); //zamieniamy warto�� string na int i przypisujemy j� do innej zmiennej
	coinsFile.close(); //zamykamy plik z monetami

	LoadSprites(); //metoda do �adowania grafik do tabeli 'sprites'
	shop.GetSprites(sprites);// sklep �aduje sobie swoje grafiki z tabeli 'sprites'
	paddleChooser.GetSprites(sprites); //menu wyboru paletek �aduje swoje grafiki z tabeli 'sprites'
	level.GetSprites(sprites); // menu wyboru poziom�w �aduje swoje grafiki z tabeli 'sprites'
	window.create(sf::VideoMode(windowWidth, windowHeigth), "Arkanoid"); //tworzymy okno aplikacji
	window.setFramerateLimit(60); //ustawimay limi klatek
	state = MENU; //pierwszym stanem programy jest menu
}
void GameEngine::RunGame()
{
	while (state != END) //g��wna p�tla aplikacji, w zale�no�ci od enuma 'state' wchodzimy do odpowiedzniego menu lub samej gry
	{
		switch (state)
		{
		case GameState::MENU:
			Menu();
			break;
		case GameState::GAME:
			Game();
			break;
		case GameState::GAME_OVER:
			GameOver();
			break;
		case GameState::LEVEL_MENAGER:
			level.changeForGameState = false;
			LevelMenagerFun();
			break;
		case GameState::LEVEL_COMPLETED:
			LevelCompleted();
			break;
		case GameState::SHOP:
			Shop();
			break;
		case GameState::PADDLE_CHOOSER:
			PaddleChooser();
			break;
		}
	}
}
void GameEngine::LoadSprites()
{
	//�adujemy grfiki bonus�w
	if (!textures[6].loadFromFile(("Sprites\\coin.png"))) std::cout << "Coin Texture Error" << std::endl;
	sprites[6].setTexture(textures[6]);
	if (!textures[3].loadFromFile(("Sprites\\slowBall.png"))) std::cout << "Slow Ball Texture Error" << std::endl;
	sprites[3].setTexture(textures[3]);
	if (!textures[4].loadFromFile(("Sprites\\superBall.png"))) std::cout << "Super Ball Texture Error" << std::endl;
	sprites[4].setTexture(textures[4]);
	if (!textures[5].loadFromFile(("Sprites\\reverseControl.png"))) std::cout << "Reverse Control Texture Error" << std::endl;
	sprites[5].setTexture(textures[5]);
	if (!textures[0].loadFromFile(("Sprites\\expandPaddle.png"))) std::cout << "Expand Paddle Texture Error" << std::endl;
	sprites[0].setTexture(textures[0]);
	if (!textures[2].loadFromFile(("Sprites\\accelerateBall.png"))) std::cout << "Accelerate Ball  Texture Error" << std::endl;
	sprites[2].setTexture(textures[2]);
	if (!textures[1].loadFromFile(("Sprites\\shortenPaddle.png"))) std::cout << "Shorten Paddle Texture Error" << std::endl;
	sprites[1].setTexture(textures[1]);
	//�adujemy grfiki paletek u�ywane przez sklep i wyb�r paletek
	if (!textures[7].loadFromFile(("Sprites\\yellowPaddle.png"))) std::cout << "Yellow Paddle Texture Error" << std::endl;
	sprites[7].setTexture(textures[7]);
	if (!textures[8].loadFromFile(("Sprites\\redPaddle.png"))) std::cout << "Red Paddle Texture Error" << std::endl;
	sprites[8].setTexture(textures[8]);
	if (!textures[9].loadFromFile(("Sprites\\greenPaddle.png"))) std::cout << "Green Paddle Texture Error" << std::endl;
	sprites[9].setTexture(textures[9]);
	if (!textures[10].loadFromFile(("Sprites\\bluePaddle.png"))) std::cout << "Blue Paddle Texture Error" << std::endl;
	sprites[10].setTexture(textures[10]);
	if (!textures[11].loadFromFile(("Sprites\\whitePaddle.png"))) std::cout << "White Paddle Texture Error" << std::endl;
	sprites[11].setTexture(textures[11]);
	//�adujemy grfiki wyboru poziom�w
	if (!textures[12].loadFromFile(("Sprites\\lvl_1.png"))) std::cout << "Level1 Texture Error" << std::endl;
	sprites[12].setTexture(textures[12]);
	if (!textures[13].loadFromFile(("Sprites\\lvl_2.png"))) std::cout << "Level2 Texture Error" << std::endl;
	sprites[13].setTexture(textures[13]);
	if (!textures[14].loadFromFile(("Sprites\\lvl_3.png"))) std::cout << "Level3 Texture Error" << std::endl;
	sprites[14].setTexture(textures[14]);
	if (!textures[15].loadFromFile(("Sprites\\lvl_4.png"))) std::cout << "Level4 Texture Error" << std::endl;
	sprites[15].setTexture(textures[15]);
	if (!textures[16].loadFromFile(("Sprites\\lvl_5.png"))) std::cout << "Level5 Texture Error" << std::endl;
	sprites[16].setTexture(textures[16]);
	if (!textures[17].loadFromFile(("Sprites\\lvl_6.png"))) std::cout << "Level6 Texture Error" << std::endl;
	sprites[17].setTexture(textures[17]);
	if (!textures[18].loadFromFile(("Sprites\\lvl_7.png"))) std::cout << "Level7 Texture Error" << std::endl;
	sprites[18].setTexture(textures[18]);
	if (!textures[19].loadFromFile(("Sprites\\lvl_8.png"))) std::cout << "Level8 Texture Error" << std::endl;
	sprites[19].setTexture(textures[19]);
	if (!textures[20].loadFromFile(("Sprites\\lvl_9.png"))) std::cout << "Level9 Texture Error" << std::endl;
	sprites[20].setTexture(textures[20]);
	if (!textures[21].loadFromFile(("Sprites\\lvl_10.png"))) std::cout << "Level10 Texture Error" << std::endl;
	sprites[21].setTexture(textures[21]);


	for (int i = 0; i < 6; i++)
	{
		sprites[i].setOrigin(rect.getOrigin().x + 70, rect.getOrigin().y + 20);
		sprites[i].setScale(0.5f, 0.7); //dopasowywujemy wielko�� bonus�w
	}
	sprites[6].setOrigin(rect.getOrigin().x+10 , rect.getOrigin().y+10 );
	sprites[6].setScale(1.5f,1.5f); //moneta ma inny rozmiar wi�c j� musimy zrobi� oddzielnie
}

//Menu i zwiazane z nim funkcje
void GameEngine::Menu()
{

	sf::Text title("Arkanoid!", font, 150);
	title.setFillColor(sf::Color::Cyan);
	title.setPosition((windowWidth - title.getGlobalBounds().width) / 2, (windowHeigth / 20)); //ustawiamy tytu�

	const int howMuchTexts = 3;
	sf::Text texts[howMuchTexts];

	SetMenuTexts(howMuchTexts, texts); //ustawiamy pozosta�e teksty w menu

	while (state == MENU) //p�tla dla Menu
	{
		window.clear(); //czy�cimy ekran

		sf::Vector2f mouse(sf::Mouse::getPosition(window)); //zczytujemy pozycje myszki
		sf::Event event;

		while (window.pollEvent(event)) CheckMenuEvents(event, texts, mouse); //sprawdzamy zdarzenia (klikni�cie menu) dla menu

		ColorMenuTexts(howMuchTexts, texts, mouse); //funkcja kt�ra zmienia kolor tekstu je�li najedziemy na niego myszk�

		for (int i = 0; i < howMuchTexts; i++) window.draw(texts[i]); //wy�wietlamy na ektanie wszystkie teksty

		window.draw(title);//wy�wietlamy na ektanie tytu�
		window.display();

	}
}
void GameEngine::Save()
{
	coinsFile.open("Files\\amountOfCoins.txt", std::ios::out|std::ios::trunc); //otwieramy plik z monetami przy okazji czyszcz�c go
	coinsFile.clear();
	coinsFile.seekp(std::ios::beg); //ustawiamy kursor na pocz�tek
	coinsFile << amountOfCoins; //zapisujemy monety dol pliku
	coinsFile.close();//zamykamy plik
	level.SaveLevels();//zapisujemy poziomy kt�re przeszli�my
	shop.SaveItems();//zapisujemy przedmioty kt�re kupili�my
	state = END; //wychodzimy z gry
}
void GameEngine::SetMenuTexts(int howMuchTexts, sf::Text texts[])
{
	std::string str[] = { "Play","Shop","Exit" };

	for (int i = 0; i < howMuchTexts; i++)
	{
		texts[i].setFont(font);
		texts[i].setCharacterSize(85);

		texts[i].setString(str[i]);
		texts[i].setPosition((windowWidth - texts[i].getGlobalBounds().width) / 2, windowHeigth / 3 + (i * 120));
	}
}
void GameEngine::ColorMenuTexts(int howMuchTexts, sf::Text texts[],sf::Vector2f mouse)
{
	for (int i = 0; i < howMuchTexts; i++)
	{
		if (texts[i].getGlobalBounds().contains(mouse))
			texts[i].setFillColor(sf::Color::Magenta);
		else texts[i].setFillColor(sf::Color::Cyan);
	}
}
void GameEngine::CheckMenuEvents(sf::Event event, sf::Text texts[],sf::Vector2f mouse)
{
	if (((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) ||
		((texts[2].getGlobalBounds().contains(mouse)) && (event.type == sf::Event::MouseButtonReleased) && (event.key.code == sf::Mouse::Left)))
	{
		Save(); //jesli klikniemy ESC lub 'Exit' w menu to zapisujemy stan gry i wychodzimy z aplikacji
	}
	else if ((texts[0].getGlobalBounds().contains(mouse)) && (event.type == sf::Event::MouseButtonReleased) && (event.key.code == sf::Mouse::Left))
		state = PADDLE_CHOOSER; //je�li myszka znajduje si� w tekscie "play" i zwolnimy przycisk wchodzimy do menu wyboru paletki
	else if ((texts[1].getGlobalBounds().contains(mouse)) && (event.type == sf::Event::MouseButtonReleased) && (event.key.code == sf::Mouse::Left))
		state = SHOP; //je�li myszka znajduje si� w tekscie "shop" i zwolnimy przycisk wchodzimy do sklepu
}
//Wybor paletek i zwiazane z tym funkcje
void GameEngine::PaddleChooser()
{
	redPaddle.Deactive();
	bluePaddle.Deactive();
	greenPaddle.Deactive();
	yellowPaddle.Deactive(); //deaktywujemy wszystkie paletki

	while (state == PADDLE_CHOOSER) //p�tla dla Menu wyboru paletek
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(window)); //pozycja myszki
		sf::Event event;

		window.clear(); //czy�cimy ekran

		paddleChooser.DisableButton(); //ustawiamy zwolni�cie przycisku na fa�sz
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) state = END; //po naci�ni�ciu krzy�yka wychodzimy
			else if (((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) state = MENU; //po klikni�ciu ESC wracamy do Menu
			paddleChooser.IsButtonReleased(event); //przesy�amy zdarzenia do metody z klasy paddlechoser i je�li zwolnimy przycisk to wybieramy paletke
		}

		int paddleNumber = paddleChooser.Update(mouse);  //update przesy�a id paletki kt�r� wybrali�my lub 5 gdy nie wybrai�my �adnej
		if (paddleNumber != 5) ChoosePaddle(paddleNumber); //je�li jest to warto�� r�na od 5 to wybrali�my paletk�

		for (int i = 0; i < howMuchItems + 1; i++) window.draw(paddleChooser.paddlesPictures[i]);
		for (int i = 0; i < howMuchItems + 1; i++) window.draw(paddleChooser.blackRecktangles[i]);
		for (int i = 0; i < howMuchItems + 1; i++) window.draw(paddleChooser.paddlesSprites[i]);
		for (int i = 0; i < howMuchItems + 1; i++) window.draw(paddleChooser.paddlesNamesText[i]); //rysujemy paletki w sklepie
		window.display();
	}
}
void GameEngine::ChoosePaddle(int paddleNumber)
{
	// na podstawie warto�� przes�anej przez metod� update aktywujemy paletk� j�sli jest przez nas kupiona
	//przechodzimy do wyboru poziom�w
	if ((paddleNumber == 0) && (shop.availableItems[paddleNumber] == true))
	{
		yellowPaddle.SetActive();
		paddleChooser.SetNewPlayer(player, yellowPaddle);
		state = LEVEL_MENAGER;
	}
	else if ((paddleNumber == 1) && (shop.availableItems[paddleNumber] == true))
	{
		redPaddle.SetActive();
		paddleChooser.SetNewPlayer(player, redPaddle);
		state = LEVEL_MENAGER;
	}
	else if ((paddleNumber == 2) && (shop.availableItems[paddleNumber] == true))
	{
		greenPaddle.SetActive();
		paddleChooser.SetNewPlayer(player, greenPaddle);
		state = LEVEL_MENAGER;
	}
	else if ((paddleNumber == 3) && (shop.availableItems[paddleNumber] == true))
	{
		bluePaddle.SetActive();
		paddleChooser.SetNewPlayer(player, bluePaddle);
		state = LEVEL_MENAGER;
	}
	else if ((paddleNumber == 4))
	{
		paddleChooser.SetNewPlayer(player, player);
		state = LEVEL_MENAGER;
	}

}
//Funkcja pokazujaca wybor poziomow
void GameEngine::LevelMenagerFun()
{
	sf::Vector2f mouse(sf::Mouse::getPosition(window));
	sf::Event event;

	while (state == LEVEL_MENAGER)
	{
		mouse = (sf::Vector2f)(sf::Mouse::getPosition(window)); //pozycja myszy
		window.clear(); //czyszczenie ekranu

		level.DisableButton(); //ustawiamy zwolni�cie przycisku na fa�sz

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) state = END; //po naci�ni�ciu krzy�yka wychodzimy
			else if (((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) state = MENU; //po klikni�ciu ESC wracamy do Menu
			level.IsButtonReleased(event); //przesy�amy zdarzenia do metody z klasy levelmenager i je�li zwolnimy przycisk to wybieramy poziom w kt�ry chcemy zagra�
		}

		for (int i = 0; i <howMuchLevels; i++) window.draw(level.levelsPictures[i]);
		for (int i = 0; i <howMuchLevels; i++) window.draw(level.levelsSprites[i]);
		for (int i = 0; i <howMuchLevels; i++) window.draw(level.levelNumber[i]); //rysujemy grafiki poziom�w

		if (level.changeForGameState == true) state = GAME; //je�li wybrali�my poziom to mo�emy zmieni� stan aplikacji na 'gra'
		level.Update(mouse); //funkcja sprawdza czy wybrali�my odpowiedni poziom i zmienia warto�� zmiennej 'changeForGameState' je�li tak si� sta�o
		window.display();
	}
}

//Gra i zwiazane z nia funkcje
void GameEngine::Game()
{
	std::vector<Block> blocks; //tablica wektorowa blok�w
	std::vector<Bonus> bonuses; // tablica wektorowa bonus�w

	level.LoadLevel(ball, player, blocks); //funkcja kt�ra �aduje wybrany przez nas wcze�niej poziom, wysy�amy do niej pi�k� i paletk� aby je ustawi�a oraz tablic� blok�w do uzupe�nienia
	ball.MoveStraightDown(); //na pocz�tku pi�ka ma spada� pionowo w d�
	player.Reset(); //resetujemy pr�dko�� i rozmiar gracza
	ball.Reset(); //resetujemy pr�dko�� pi�ki
	while (state == GAME) //p�tla gry
	{
		sf::Event event;

		window.clear(); //czy�cimy ekran
		superBall.GetTime(); //sprawdzamy ile czasu trwa bonus superBall

		while (window.pollEvent(event))
		{
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)))
				state = MENU; //klikni�cie ESC cofa nas do menu
		}

		ball.Update(); //poruszanie pi�ki
		player.Update(); //kontrola gracza

		if (Collisions(player, ball)) player.SetPosition(player.GetPosition().x, player.GetPosition().y - 1); //za ka�dym odbiciem pi�ki gracz podnosi si� lekk do g�ry

		if (redPaddle.IsActive()) RedPaddleSpecial();
		else if (bluePaddle.IsActive()) BluePaddleSpecial(); //sprawdzamy czy kt�ra� ze specjalnych paletek jest aktywna

		UpdateAndRemoveBlocks(blocks, bonuses); //funkcja zajmuj�ca si� niszczeniem blok�w i tworzeniem bonus�w
		UpdateAndRemoveBonuses(bonuses); //funkcja niszcz�ca bonusy

		if (blocks.empty()) //sprawdzamy czy wszystkie bloki s� zniszczone i je�li tak to gracz wygra� poziom
		{
			level.ChangeToNextLevel();
			state = LEVEL_COMPLETED;
			break;
		}
		if (CheckGameOver(ball)) //sprawdzamy czy gracz przegra�
		{
			if (greenPaddle.IsActive()) GreenPaddleSpecial();
			else state = GAME_OVER;
		}

		window.draw(coins.ShowCoinsInGame(amountOfCoins)); //wy�wietlamy ile gracz ma monet
		window.draw(ball); //wy�wietlamy pi�ke
		window.draw(player.sprite); //wy�wietlamy gracza
		window.display();
	}
}
void GameEngine::RedPaddleSpecial()
{
	//je�li czerwona paletka jest aktywna to rysujemy jeszcze dodatkowa paletke i sprawdzamy jej kolizje z pi�k�
	window.draw(redPaddle.secondPaddle.rect);
	redPaddle.UpdateSecondPaddle();
	Collisions(redPaddle.secondPaddle, ball);
}
void GameEngine::GreenPaddleSpecial()
{
	//je�li zielona paletka jest aktywna sprawdzamy dodatkow czy gracz straci� wszystkie �ycia
	greenPaddle.RemoveLife();
	if (greenPaddle.HowManyLivesLeft() < 0) state = GAME_OVER;
}
void GameEngine::BluePaddleSpecial()
{
	//je�li niebieska paletka jest aktywna tysujemy dodatkow� pi�k� 
	window.draw(bluePaddle.secondBall);
	bluePaddle.secondBall.Update();
}
void GameEngine::UpdateAndRemoveBlocks(std::vector<Block> &blocks, std::vector<Bonus> &bonuses)
{
	srand(time(NULL));
	int random = rand() % 13 + 1;// liczba losowa do losowanie czy i jaki bonus ma si� pojawi�

	for (auto& block : blocks)
	{
		//rysujemy ka�dy blok
		window.draw(block); 
		//je�li nast�pi kolizja to mo�e zosta� wywo�ana funkcja zwracaj�ca bonus i bonus ten zostaje dodany do tablicy
		if ((Collisions(block, ball))&&(random<8)&&(random>0)) bonuses.emplace_back(SpawnBonus(block.GetPosition().x, block.GetPosition().y,random));
		//jesli niebieska paletka jest aktywna to sprawdzamy jeszcze kolizje dodatkowej pi�ki z blokami
		if (bluePaddle.IsActive()) Collisions(block, bluePaddle.secondBall);
	}

	auto iteratorBlocks = remove_if(begin(blocks), end(blocks), [](Block& block) {return block.IsDestroyed(); });
	blocks.erase(iteratorBlocks, end(blocks)); //usuwamy zniszczone bloki z tablicy wektor�w
}
void GameEngine::UpdateAndRemoveBonuses(std::vector<Bonus> &bonuses)
{
	for (auto& bonus : bonuses)
	{
		if (Collisions(bonus, player)) UseBonus(bonus.GetId()); //je�li nast�pi kolizja mni�dzy graczem a bonusem to pobieramy id bonusu i porzesy�amy je do funkcji UseBonus
		if (bonus.GetPosition().y >= windowHeigth) bonus.Destroy(); //je�li niezebrany bonus spadnie poza okno to zostaje zniszczony
		bonus.MoveDown();//kazdy bonus w d�
		window.draw(bonus.sprite); //rysujemy ka�dy bonus na ekranie
	}

	auto iteratorBonus = remove_if(begin(bonuses), end(bonuses), [](Bonus &bonus) {return bonus.IsDestroyed(); });
	bonuses.erase(iteratorBonus, end(bonuses)); //usuwamy z tablic zniszczone bonusy
}
bool GameEngine::CheckGameOver(Ball &ball)
{
	if (ball.GetPosition().y >= windowHeigth - ball.GetRadius()) return true;
	else return false; //je�li pi�ka dotknie dolnej kraw�dzi to przegrywamy
}
Bonus GameEngine::SpawnBonus(float pos_X, float pos_Y, int rand)
{
	//na podstawie id bonusu i pozycji zniszczonego bloku tworzymy bonus na tej w�a�nie pozycji i przypisujemy mu grafik�
	if (rand == 1)
	{
		ExpandPaddle expandBonus(pos_X, pos_Y,sprites[0]);
		return expandBonus;
	}
	else if (rand == 2)
	{
		ShortenPaddle shortenBonus(pos_X, pos_Y, sprites[1]);
		return shortenBonus;
	}
	else if (rand == 3)
	{
		AccelerateBall accelerateBonus(pos_X, pos_Y, sprites[2]);
		return accelerateBonus;
	}
	else if (rand == 4)
	{
		SlowBall slowBonus(pos_X, pos_Y, sprites[3]);
		return slowBonus;
	}
	else if (rand == 5)
	{
		SuperBall superBallBonus(pos_X, pos_Y, sprites[4]);
		return superBallBonus;
	}
	else if (rand == 6)
	{
		ReverseControl reverseBonus(pos_X, pos_Y, sprites[5]);
		return reverseBonus;
	}
	else if (rand == 7)
	{
		Coins coin(pos_X, pos_Y, sprites[6]);
		return coin;
	}
}
void GameEngine::UseBonus(int id)
{
	ExpandPaddle expandBonus;
	ShortenPaddle shortenBonus;
	AccelerateBall accelerateBonus;
	SlowBall slowBonus;
	//na podstawie przes�anego id bonusu u�ywamy odpowiedniej funkcji specjalnej lub otrzymujemy komunikat o b��dzie
	switch (id)
	{
	case 1: expandBonus.Expand(player); break;
	case 2: shortenBonus.Shorten(player); break;
	case 3: accelerateBonus.Accelerate(ball); break;
	case 4: slowBonus.Slow(ball); break;
	case 5: superBall.Restart(); superBall.help = 1; break; //restarujemy zegar aby czas trwania superball by� mniejszy od 10 
	case 6: player.ChangeControl(); break;
	case 7:
		if (yellowPaddle.IsActive()) amountOfCoins += 10;
		else amountOfCoins+=5;
		break;
	default: std::cout << "Id error" << std::endl; break;
	}
}



//Komunikat o porazce i zwiazane z tym funkcje
void GameEngine::GameOver()
{
	const int howMuchTexts = 3; 
	sf::Text texts[howMuchTexts];
	SetUpGameOverTexts(howMuchTexts, texts);


	while (state == GAME_OVER)
	{
		window.clear();
		sf::Event event;

		while (window.pollEvent(event))
		{
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))) state = MENU;
		}

		for (int i = 0; i < howMuchTexts; i++)
			window.draw(texts[i]);

		window.display();

	}
}
void GameEngine::SetUpGameOverTexts(int howMuchTexts, sf::Text texts[])
{
	std::string str[] = { "You Lost!","Press Space", "to continue" };
	for (int i = 0; i < howMuchTexts; i++)
	{
		texts[i].setFont(font);
		texts[i].setString(str[i]);
		texts[i].setCharacterSize(60);
		texts[i].setFillColor(sf::Color::Cyan);
		texts[i].setPosition((windowWidth - texts[i].getGlobalBounds().width) / 2, (windowHeigth / 2) + (i * 70));
	}
	texts[0].setCharacterSize(150);
	texts[0].setPosition((windowWidth - texts[0].getGlobalBounds().width) / 2, windowHeigth / 7);
}

//Komunikat o wygranej i zwiazane funkcje
void GameEngine::LevelCompleted()
{
	sf::Text levelText, continueText, menuText;
	SetUpLevelCompletedTexts(levelText, continueText, menuText);
	level.availableLevels[(int)(level.lvl)] = true;

	while (state == LEVEL_COMPLETED)
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)))
				state = GAME;
			else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)))
				state = MENU;
		}
		window.draw(levelText);
		window.draw(continueText);
		window.draw(menuText);
		window.display();
	}
}
void GameEngine::SetUpLevelCompletedTexts(sf::Text &levelText, sf::Text &continueText, sf::Text &menuText)
{
	

	levelText.setString("    Level \ncompleted!");
	levelText.setFont(font);
	levelText.setCharacterSize(150);
	levelText.setPosition(200, 75);
	levelText.setFillColor(sf::Color::Cyan);

	continueText.setString("Press Space to continue");
	continueText.setFont(font);
	continueText.setCharacterSize(60);
	continueText.setPosition(250, 500);
	continueText.setFillColor(sf::Color::Cyan);

	menuText.setString("Press Escape to continue");
	menuText.setFont(font);
	menuText.setCharacterSize(60);
	menuText.setPosition(235, 575);
	menuText.setFillColor(sf::Color::Cyan);
}

//Sklep i zwiazane z nim funkcje
void GameEngine::Shop()
{
	while (state == SHOP)
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(window)); //pozycja myszy
		sf::Event event;

		window.clear(); //czyszczenie ekranu
		shop.DisableButton(); //ustawiamy zwolni�cie przycisku na fa�sz
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) state = END; //zamykamy krzy�ykiem aplikacje
			else if (((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) state = MENU; //ESC wychodzimy do menu
			shop.IsButtonReleased(event); //przesy�amy zdarzenia do metody z klasy shop i je�li zwolnimy przycisk to wybieramy paletk� kt�r� chcemy kupi�
		}

		CheckBuyingItems(mouse); //sprawdzamy mo�liwo�� kupienia paletki na kt�r� najecha� myszka

		for (int i = 0; i < howMuchItems; i++) window.draw(shop.shopItems[i]);
		for (int i = 0; i < howMuchItems; i++) window.draw(shop.blackRecktangles[i]);
		for (int i = 0; i < howMuchItems; i++) window.draw(shop.ItemsSprites[i]);
		for (int i = 0; i < howMuchItems; i++) window.draw(shop.shopItemNames[i]);
		window.draw(coins.ShowCoinsInShop(amountOfCoins));

		window.display();
	}

}
void GameEngine::CheckBuyingItems(sf::Vector2f mouse)
{
	switch (shop.Update(mouse, window)) //na podstawie zwracanej przez update liczby kupujemy paletk� je�li �adna nie jest wybrana metoda zwraca 4
	{
	case 0: shop.BuyPaddle(yellowPaddle, amountOfCoins); break;
	case 1: shop.BuyPaddle(redPaddle, amountOfCoins); break;
	case 2: shop.BuyPaddle(greenPaddle, amountOfCoins); break;
	case 3: shop.BuyPaddle(bluePaddle, amountOfCoins); break;
	default: break;
	}
}




//Funkcje zwiazane z kolizjami obiektow
template <class T1, class T2> bool GameEngine::IsIntersecting(T1 &A, T2 &B)
{
	return ((A.Right() >= B.Left()) && (A.Left() <= B.Right())
		&& (A.Bottom() >= B.Top()) && (A.Top() <= B.Bottom()));  //funkcja template sprrawdzaj�ca czy dwa dowolne obiekty na siebie nachodz�
}
bool GameEngine::Collisions(Paddle &paddle, Ball &ball) //sprawdza kolizje paletki i pi�ki
{
	if (!IsIntersecting(paddle, ball)) return false; //je�li na siebie nie nachodz� to zwracamy fa�sz w innym wypadu poruszamy pi�k� do g�ry 
	ball.MoveUp();                                   // i  w prawo lub lewo w zale�no�ci w kt�r� stron� paletki uderzy�a
	if (ball.GetPosition().x < paddle.GetPosition().x) ball.MoveLeft(); 
	else if (ball.GetPosition().x > paddle.GetPosition().x) ball.MoveRight();

}
bool GameEngine::Collisions(Block &block, Ball &ball) //sprawdza kolizje bloku i pi�ki
{
	if (!IsIntersecting(block, ball)) return false; //je�li na siebie nie nachodz� to zwracamy fa�sz
	block.Destroy(); //niszczymy blok trafiony pi�k�
	if ((superBall.ElapsedTime() > superBall.Duration())||(superBall.help==0)) //je�li czas trwania superball jest mniejszy od 10 to odbijamy pi�k� (w przeciwnym razie pi�ka niszczy wszystkie napotkane bloki)
	{                                                                          //(w przeciwnym razie pi�ka niszczy wszystkie napotkane bloki i si� od nich nie odbija)
		float overLapLeft = ball.Right() - block.Left();
		float overLapRight = block.Right() - ball.Left();
		float overLapTop = ball.Bottom() - block.Top();
		float overLapBottom = block.Bottom() - ball.Top();

		bool ballFromLeft = (abs(overLapLeft) < abs(overLapRight));
		bool ballFromTop = (abs(overLapTop) < abs(overLapBottom));  //sprawdzamy jak pi�ka uderzy�a w blok

		float minOverLapX{ ballFromLeft ? overLapLeft : overLapRight };
		float minOverLapY{ ballFromTop ? overLapTop : overLapBottom };

		if (abs(minOverLapX) < abs(minOverLapY)) ballFromLeft ? ball.MoveLeft() : ball.MoveRight(); //odbijamy j� w prawo lub w lewo
		else ballFromTop ? ball.MoveUp() : ball.MoveDown();                                         //oraz w g�r� lub w d�
	}
}
bool GameEngine::Collisions(Bonus &bonus, Paddle &paddle) //sprawdza kolizje bonusu i pi�ki
{
	if (!IsIntersecting(bonus, paddle)) return false; //je�li na siebie nie nachodz� to zwracamy fa�sz
	bonus.Destroy();                                  //w innym wypadku niszczym blok
}