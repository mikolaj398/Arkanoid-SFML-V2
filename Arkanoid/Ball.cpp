#include "Ball.h"

Ball::Ball()
{
	circle.setRadius(this->ballRadius); 
	circle.setOrigin(this->ballRadius, this->ballRadius);
	circle.setFillColor(sf::Color::White);
}
void Ball::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(this->circle, state);
}

void Ball::Update()
{
	circle.move(this->velocity); //zmiana po³o¿enia pi³ki

	if (this->Left() < 0) MoveRight(); //odbicie od lewej krawêdzi
	else if (this->Left() > 1280) MoveLeft();// odbicie od prawej krawêdzi

	if (this->Top() < 0) MoveDown(); //odbicie od górnej krawêdzi
	else if (this->Bottom() > 800) MoveUp(); //odbicei od dolenej krawêdzi
}
float Ball::Left()
{
	return this->circle.getPosition().x - this->circle.getRadius();
}
float Ball::Right()
{
	return this->circle.getPosition().x + this->circle.getRadius();
}
float Ball::Top()
{
	return this->circle.getPosition().y - this->circle.getRadius();
}
float Ball::Bottom()
{
	return this->circle.getPosition().y + this->circle.getRadius();
}

void Ball::MoveLeft()
{
	this->velocity.x = -ballSpeed;
}
void Ball::MoveRight()
{
	this->velocity.x = ballSpeed;
}
void Ball::MoveUp()
{
	this->velocity.y = -ballSpeed;
}
void Ball::MoveDown()
{
	this->velocity.y = ballSpeed;
}
void Ball::MoveStraightDown()
{
	this->velocity.y = ballSpeed;
	this->velocity.x = 0;
}

sf::Vector2f Ball::GetPosition()
{
	return circle.getPosition();
}
void Ball::SetPosition(int pos_X,int pos_Y)
{
		circle.setPosition(pos_X, pos_Y);
}

float Ball::GetRadius()
{
	return this->ballRadius;
}

void Ball::ChangeSpeed(int change)
{
	if ((change < 0) && (this->ballSpeed <= 2)) return; //nie zmniejszamy prêdkoœci pi³ki jeœli te jest ju¿ równa 2 lub mniej
	this->ballSpeed += change;
}
void Ball::Reset()
{
	this->ballSpeed = this->ballVelocity;
}
void Ball::ChangeColor(sf::Color color)
{
	circle.setFillColor(color);
}
