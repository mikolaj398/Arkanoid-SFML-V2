#include "Paddle.h"

Paddle::Paddle()
{
	rect.setSize({ this->paddleWidth,this->paddleHeigth });
	rect.setOrigin(this->paddleWidth / 2.0f, this->paddleHeigth / 2.0f);
	rect.setFillColor(sf::Color::Red);

	if (!texture.loadFromFile(("Sprites\\whitePaddle.png"))) std::cout << "White Paddle Texture Error" << std::endl;
	sprite.setTexture(texture); //ustawiamy grafikê paletki

	sprite.setOrigin(rect.getOrigin().x-18,rect.getOrigin().y); //dopasowywujemy wielkoœæ grafiki do paletki
	sprite.setScale(1.3f, 1.0f);
	
}
void Paddle::Reset()
{
	//przywracamy paletce pocz¹tkowe statystyki
	rect.setSize({ this->paddleWidth,this->paddleHeigth });
	rect.setOrigin(this->paddleWidth / 2.0f, this->paddleHeigth / 2.0f);
	sprite.setScale(1.3f, 1.0f);
}
void Paddle::Update()
{
	rect.move(this->velocity); //przesuwamy paletkê
	sprite.setPosition(rect.getPosition().x,rect.getPosition().y); //ustawiamy teksturê paletki na paletce
	if (control == 1) NormalControl(); //zmieniamy system sterowania w zale¿noœci od zmiennej 'control'
	else ReverseControl();
	
}
void Paddle::SetActive()
{
	active = true; //uaktywniamy paletke
}
void Paddle::Deactive()
{
	active = false; //dezaktywujemy paletkê
}
bool Paddle::IsActive()
{
	return active; //sprawdzamy czy paletka jest aktywna
}

int Paddle::GetId()
{
	return this->id; //zwracamy id paletki
}
int Paddle::GetPrice()
{
	return this->price; //zwracamy cenê paletki
}
void Paddle::ChangeControl()
{
	this->control *= (-1); //zmieniamy system sterowania na przeciewny
}
void Paddle::NormalControl()
{ // noramlne sterowanie -> strza³ka w lewo powoduje ruch paletki w lewo a strza³ka w prawo powoduje ruch w prawo
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) && (this->Left() > 0))
	{
		velocity.x = -this->paddleVelocity;
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) && (this->Right() < windowWidth))
	{
		velocity.x = this->paddleVelocity;
	}
	else
	{
		velocity.x = 0.0f;
	}
}
void Paddle::ReverseControl()
{// noramlne sterowanie -> strza³ka w lewo powoduje ruch paletki w prawo a strza³ka w prawo powoduje ruch w lewo
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) && (this->Left() > 0))
	{
		velocity.x = -this->paddleVelocity;
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) && (this->Right() < windowWidth))
	{
		velocity.x = this->paddleVelocity;
	}
	else
	{
		velocity.x = 0.0f;
	}
}
void Paddle::ChangeSize(int increase)
{//zmiana wielkoœci paletki
	float newWidth = rect.getSize().x + increase; //do starej wielkoœci dodajemy now¹
	rect.setSize({ newWidth,this->paddleHeigth }); //ustawiamy now¹ wielkoœæ
	rect.setOrigin(newWidth / 2.0f, this->paddleHeigth / 2.0f); //ustawiamy nowy origin wed³ug nowej wielkoœci

	sprite.setScale(rect.getSize().x/115.0f, 1.0f); //dopasowywujemy wielkoœæ tekstury
}

