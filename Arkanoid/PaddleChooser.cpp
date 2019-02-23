#include "PaddleChooser.h"

PaddleChooser::PaddleChooser()
{
	
	if (!font.loadFromFile("Fonts\\Gameplay.ttf"))
		return;
	SetPaddlesPictures();
	SetPaddlesTexts();
}
void PaddleChooser::GetSprites(sf::Sprite sprites[])
{
	for (int i = 0; i < howMuchPaddles; i++)
	{
		paddlesSprites[i] = sprites[i + 7];
		paddlesSprites[i].setPosition(paddlesPictures[i].getPosition().x - 108, paddlesPictures[i].getPosition().y - 22);
		paddlesSprites[i].setScale(1.7, 1.7f);
	}
}
void PaddleChooser::SetPaddlesPictures()
{
	for (int i = 0; i < howMuchPaddles; i++)
	{
		if (i<2)
		{
			paddlesPictures[i].setPosition(200 + (i * 875), 150);
		}
		else
		{
			paddlesPictures[i].setPosition(200 + ((i - 2) * 875), windowHeigth - 250);
		}
		paddlesPictures[i].setFillColor(sf::Color::Cyan);
		paddlesPictures[i].setSize({ 230	,100 });
		paddlesPictures[i].setOrigin(230 / 2.0f, 100 / 2.0f);

		blackRecktangles[i].setOrigin(this->blackRectangleWidth / 2.0f, this->blackRectangleHeigth / 2.0f);
		blackRecktangles[i].setPosition(paddlesPictures[i].getPosition().x, paddlesPictures[i].getPosition().y);
		blackRecktangles[i].setSize({ this->blackRectangleWidth,this->blackRectangleHeigth });
		blackRecktangles[i].setFillColor(sf::Color::Black);
	}
	paddlesPictures[4].setPosition(windowWidth / 2, windowHeigth / 2);
	blackRecktangles[4].setPosition(paddlesPictures[4].getPosition());
}
void PaddleChooser::SetPaddlesTexts()
{
	std::string itemNames[howMuchPaddles] = { "Yellow","Red","Green","Blue", "White" };
	for (int i = 0; i < howMuchPaddles; i++)
	{
		if (i<2) paddlesNamesText[i].setPosition(200 + (i * 875), 275);
		else paddlesNamesText[i].setPosition(200 + ((i - 2) * 875), windowHeigth - 125);
		paddlesNamesText[i].setString(itemNames[i]);
		paddlesNamesText[i].setFont(font);
		paddlesNamesText[i].setCharacterSize(30);
		paddlesNamesText[i].setOrigin(  paddlesNamesText[i].getLocalBounds().left + paddlesNamesText[i].getLocalBounds().width / 2.0f,
										paddlesNamesText[i].getLocalBounds().top + paddlesNamesText[i].getLocalBounds().height / 2.0f);
	}
	paddlesNamesText[4].setPosition(windowWidth / 2, (windowHeigth / 2) + 125);
	paddlesNamesText[0].setFillColor(sf::Color::Yellow);
	paddlesNamesText[1].setFillColor(sf::Color::Red);
	paddlesNamesText[2].setFillColor(sf::Color::Green);
	paddlesNamesText[3].setFillColor(sf::Color::Blue);
}
int PaddleChooser::Update(sf::Vector2f mouse)
{
	for (int i = 0; i < howMuchPaddles; i++)
		{
			if (paddlesPictures[i].getGlobalBounds().contains(mouse)) //je¿eli tekst zawiera myszkê to podœwietla siê na inny kolor
			{
				paddlesPictures[i].setFillColor(sf::Color::Magenta);
				if (buttonReleased==true) return i; //po zwolnieniu przycisku metoda zwraca id paletki na któr¹ nacisneliœmy
			}
			else paddlesPictures[i].setFillColor(sf::Color::Cyan);
		}
	return 5; //jeœli nie nacisneliœmy na ¿adn¹ zwraca 5

}
void PaddleChooser::IsButtonReleased(sf::Event event)
{
	if ((event.type == sf::Event::MouseButtonReleased) && (event.key.code == sf::Mouse::Left)) this->buttonReleased = true;
}
void PaddleChooser::DisableButton()
{
	this->buttonReleased = false;
}
PaddleChooser::~PaddleChooser()
{
}
void PaddleChooser::SetNewPlayer(Paddle &oldPlayer, Paddle &newPlayer)
{
	oldPlayer.rect.setFillColor(newPlayer.rect.getFillColor()); //ustawiamy kolor gracza na kolor nowego gracza 
	oldPlayer.sprite.setTexture(newPlayer.texture); //ustawiamy teksture gracza na teksture nowego gracza 
}