#include "Shop.h"

Shop::Shop()
{
	if (!font.loadFromFile("Fonts\\Gameplay.ttf"))
		return;
	SetUpItemsPictures();
	SetUpItemsTexts();
	LoadAvailableItems();
	OpenDescriptions();
}
void Shop::GetSprites(sf::Sprite sprites[])
{
	for (int i = 0; i < howMuchItems; i++)
	{
		ItemsSprites[i] = sprites[i+7];
		ItemsSprites[i].setPosition(shopItems[i].getPosition().x-108,shopItems[i].getPosition().y-22);
		ItemsSprites[i].setScale(1.7, 1.7f);
	}
}
void Shop::SetUpItemsPictures()
{
	for (int i = 0; i < howMuchItems; i++)
	{
		if (i<2)
		{
			shopItems[i].setPosition(200 + (i * 875), 150);
		}
		else
		{
			shopItems[i].setPosition(200 + ((i - 2) * 875), windowHeigth - 250);
		}
		shopItems[i].setFillColor(sf::Color::Cyan);
		shopItems[i].setOrigin(this->shopItemWidth / 2.0f, this->shopItemHeigth / 2.0f);
		shopItems[i].setSize({ this->shopItemWidth, this->shopItemHeigth });

		blackRecktangles[i].setOrigin(this->blackRectangleWidth / 2.0f, this->blackRectangleHeigth / 2.0f);
		blackRecktangles[i].setPosition(shopItems[i].getPosition().x,shopItems[i].getPosition().y);
		blackRecktangles[i].setSize({ this->blackRectangleWidth,this->blackRectangleHeigth });
		blackRecktangles[i].setFillColor(sf::Color::Black);
	}
}
void Shop::SetUpItemsTexts()
{
	std::string itemNames[4] = { "Yellow\n    200","Red\n300","Green\n  400","Blue\n 500" };

	for (int i = 0; i < howMuchItems; i++)
	{
		if (i < 2) shopItemNames[i].setPosition(175 + (i * 890), 300);
		else  shopItemNames[i].setPosition(180 + ((i - 2) * 885), windowHeigth - 100);
		shopItemNames[i].setString(itemNames[i]);
		shopItemNames[i].setFont(font);
		shopItemNames[i].setOrigin( shopItemNames[i].getLocalBounds().left + shopItemNames[i].getLocalBounds().width / 2.0f,
									shopItemNames[i].getLocalBounds().top + shopItemNames[i].getLocalBounds().height / 2.0f);
		shopItemNames[i].setCharacterSize(40);
	}
	shopItemNames[0].setFillColor(sf::Color::Yellow);
	shopItemNames[1].setFillColor(sf::Color::Red);
	shopItemNames[2].setFillColor(sf::Color::Green);
	shopItemNames[3].setFillColor(sf::Color::Blue);
}
void Shop::LoadAvailableItems()
{
	shopFile.open("Files\\items.txt");
	std::string pom; //pomocnicz zmienna do przechowywania czytanego z pliku wiersz
	int i = 0;
	while (shopFile.eof() != true)
	{
		std::getline(shopFile, pom); //czytanie wiersz pliku
		availableItems[i] = StringToBool(pom); //wpisywanie do tablicy zmienionej na bool wartoœci string
		i++;
	}
}
void Shop::SaveItems()
{
	shopFile.clear(); //czyszczenie pliku z dostêpnymi paletkiami
	shopFile.seekp(std::ios::beg);// przenoszzenie kursora na pocz¹tek
	for (int i = 0; i < howMuchItems; i++)
	{
		shopFile << availableItems[i] << std::endl; //zapisywanie do pliku dostêpnych paletek
	}
	shopFile.close();
}
bool Shop::StringToBool(std::string a)
{
	if (a == "0") return false;
	return true;
}

int Shop::Update(sf::Vector2f mouse, sf::RenderWindow &window)
{
	for (int i = 0; i < howMuchItems; i++)
		{
			
			if (shopItems[i].getGlobalBounds().contains(mouse)) //podœwietelnie paletki jeœli znajduej siê na niej myszka
			{
				window.draw(descriptions[i]); //wyœwietleni opisu paletki kiedy znajduje siê na niej myszka
				shopItems[i].setFillColor(sf::Color::Magenta);
				if (buttonReleased == true) return i; //kiedy przycisk zostanie zwolniony metoda zwraca informacjê któr¹ paletkê chce kupiæ gracz
			}
			else shopItems[i].setFillColor(sf::Color::Cyan);

		}
	return 4; //jeœli nie kliknie to metoda zwraca wartoœæ 4

}
void Shop::IsButtonReleased(sf::Event event)
{
	if ((event.type == sf::Event::MouseButtonPressed) && (event.key.code == sf::Mouse::Left)) this->buttonReleased = true;
}
void Shop::DisableButton()
{
	this->buttonReleased = false;
}

void Shop::BuyPaddle(Paddle &paddle,int &amountOfCoins)
{
	if (paddle.GetPrice() <= amountOfCoins) //je¿eli nie mamy wystarczaj¹ce pieniêdzy nie mo¿emy kupiæ paletki
	{
		availableItems[paddle.GetId()] = true; //je¿eli mo¿emy kupiæ paletkê ustawiamy w tabeli ¿e jest dostêpna i mo¿emy ni¹ graæ
		amountOfCoins -= paddle.GetPrice(); //odejmujemy koszt paletki od sumy pieniêdzy
	}
	
}

void Shop::OpenDescriptions()
{
	//przy pomocy funkcji 'OpenDescription' ³adujemy z plików odpowiednie opisy ka¿dej paletki do tabeli z opisami
	OpenDescription("Files\\yellowPaddle.txt",0);
	descriptions[0].setFillColor(sf::Color::Yellow);
	OpenDescription("Files\\redPaddle.txt", 1);
	descriptions[1].setFillColor(sf::Color::Red);
	OpenDescription("Files\\greenPaddle.txt", 2);
	descriptions[2].setFillColor(sf::Color::Green);
	OpenDescription("Files\\bluePaddle.txt", 3);
	descriptions[3].setFillColor(sf::Color::Blue);
}
void Shop::OpenDescription(std::string path, int id)
{
	std::string text = "";// zmienna która bêdzie zawiera³a ca³y opis
	std::string pom; //pomocnicz zmienna do przechowywania czytanego z pliku wiersz
	std::fstream description; //zmienna reprezentuj¹ca plik z opisem

	description.open(path, std::ios::in | std::ios::out); //otwieramy plik z podanej œcie¿ki 
	if (description.good())
	{
		while (description.eof() != true)
		{
			std::getline(description, pom); //czytamy wiersz opisu
			text += ("\n" + pom); //do ostatecznej zmiennej dodajemy przejœcie do nowej lini i dodajemy kolejny wiersz opisu
		}
	}
	else
		std::cout << "File Error" << std::endl;
	description.close();
	descriptions[id].setPosition(400, 125);  //ustawiamy w³aœciwoœci tekstu
	descriptions[id].setString(text);
	descriptions[id].setFont(font);
	descriptions[id].setCharacterSize(40);

}
Shop::~Shop()
{
}
