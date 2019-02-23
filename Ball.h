#pragma once
#include <SFML/Graphics.hpp>
class Ball : public sf::Drawable
{
public:
	Ball();//konstruktor domy�lny
	~Ball()=default; //destruktor

	void Update(); //metoda typu pustego kt�ra zarz�dza poruszanie pi�ki
	//Funkcje zwracaj�ce lew�, praw�, g�rn� i doln� kraw�d� pi�ki
	float Left();
	float Right();
	float Top();
	float Bottom();

	//poruszanie pilki
	void MoveUp(); //poruszanie pi�ki w g�r�
	void MoveDown(); //poruszanie pi�ki w d�
	void MoveLeft(); //poruszanie pi�ki w lewo
	void MoveRight(); //poruszanie pi�ki w prawo
	void MoveStraightDown(); //poruszanie pi�ki prosto w d�

	//wlasnosci pilki
	sf::Vector2f GetPosition(); //metoda typu Vector2f zwracaj�ca pozycj� pi�ki
	void SetPosition(int pos_X,int pos_Y);//metoda typu pustego ustwiaj�ca pozycj� pi�ki i przyjmuj�ca 
	                                      //dwa parametry typu ca�kowitego
	void ChangeSpeed(int change);//metoda typu pustego zmieniaj�ca szybko�� pi�ki przyjmuj�ca parametr typu ca�kowitego
	void ChangeColor(sf::Color color);//metoda typu pustego zmieniaj�ca kolor pi�ki przyjmuj�ca paramets typu Color
	float GetRadius();//metoda typu zmiennoprzecinkowego zwracaj�ca promie� pi�ki
	void Reset();// metoda typu pustego resetuj�ca szybko�� pi�ki do warto�ci domy�lnej
	
private:
	sf::CircleShape circle;// zmienna przechowuj�ca kszta�t pi�ki
	const float ballRadius = 10.0f;// sta�a przechowuj�ca promie� pi�ki
	const float ballVelocity = 5.0f;// sta�� przechowuj�ca szybko�� domy�ln� pi�ki
	float ballSpeed = ballVelocity;// zmienna typu zmiennoprzecinkowego przechowuj�ca szybko�� pi�ki
	sf::Vector2f velocity{ 0, ballVelocity }; //zmienna typu Vector2f przechowuj�ca kierunek lot pi�ki
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override; //metoda typu pustego nadpisauj�ca metod�
};                                                          //z klasy Drawable kt�ra umo�liwia pokazanie pi�ki na ekranie


