#pragma once
#include <SFML/Graphics.hpp>
class Ball : public sf::Drawable
{
public:
	Ball();//konstruktor domyœlny
	~Ball()=default; //destruktor

	void Update(); //metoda typu pustego która zarz¹dza poruszanie pi³ki
	//Funkcje zwracaj¹ce lew¹, praw¹, górn¹ i doln¹ krawêdŸ pi³ki
	float Left();
	float Right();
	float Top();
	float Bottom();

	//poruszanie pilki
	void MoveUp(); //poruszanie pi³ki w górê
	void MoveDown(); //poruszanie pi³ki w dó³
	void MoveLeft(); //poruszanie pi³ki w lewo
	void MoveRight(); //poruszanie pi³ki w prawo
	void MoveStraightDown(); //poruszanie pi³ki prosto w dó³

	//wlasnosci pilki
	sf::Vector2f GetPosition(); //metoda typu Vector2f zwracaj¹ca pozycjê pi³ki
	void SetPosition(int pos_X,int pos_Y);//metoda typu pustego ustwiaj¹ca pozycjê pi³ki i przyjmuj¹ca 
	                                      //dwa parametry typu ca³kowitego
	void ChangeSpeed(int change);//metoda typu pustego zmieniaj¹ca szybkoœæ pi³ki przyjmuj¹ca parametr typu ca³kowitego
	void ChangeColor(sf::Color color);//metoda typu pustego zmieniaj¹ca kolor pi³ki przyjmuj¹ca paramets typu Color
	float GetRadius();//metoda typu zmiennoprzecinkowego zwracaj¹ca promieñ pi³ki
	void Reset();// metoda typu pustego resetuj¹ca szybkoœæ pi³ki do wartoœci domyœlnej
	
private:
	sf::CircleShape circle;// zmienna przechowuj¹ca kszta³t pi³ki
	const float ballRadius = 10.0f;// sta³a przechowuj¹ca promieñ pi³ki
	const float ballVelocity = 5.0f;// sta³¹ przechowuj¹ca szybkoœæ domyœln¹ pi³ki
	float ballSpeed = ballVelocity;// zmienna typu zmiennoprzecinkowego przechowuj¹ca szybkoœæ pi³ki
	sf::Vector2f velocity{ 0, ballVelocity }; //zmienna typu Vector2f przechowuj¹ca kierunek lot pi³ki
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override; //metoda typu pustego nadpisauj¹ca metodê
};                                                          //z klasy Drawable która umo¿liwia pokazanie pi³ki na ekranie


