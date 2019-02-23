#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Object: public sf::Drawable
{
public:
	sf::Texture texture;//zmienna typu Texture przechowuj�ca teksture obiektu
	sf::Sprite sprite;//zmienna typu Sprite przechowuj�ca grafike obiektu
	sf::RectangleShape rect;//zmienna typu RectangleShape przechowuj�ca kszta�t obiektu
	Object();//konstruktor bezparametrowy
	~Object() = default;//destruktor

	float Left();//metoda typu zmiennoprzecinkowego zwracaj�ca lew� kraw�d� obiektu
	float Right();//metoda typu zmiennoprzecinkowego zwracaj�ca praw� kraw�d� obiektu
	float Top();//metoda typu zmiennoprzecinkowego zwracaj�ca g�rn� kraw�d� obiektu
	float Bottom();//metoda typu zmiennoprzecinkowego zwracaj�ca doln� kraw�d� obiektu
	sf::Vector2f GetPosition(); //metoda typu Vector2f zwracaj�ca pozycj� obiektu
	void SetPosition(int pos_X, int pos_Y);//metoda typu pustego ustawiaj�ca poycj� obiektu

	const static int windowWidth = 1280;//statyczna sta�a reprezentuj�ca szeroko�� renderowaego okna
	const static int windowHeigth = 800;//statyczna sta�a reprezentuj�ca wysoko�� renderowaego okna

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;//metoda typu pustego nadpisauj�ca metod�
                                                           //z klasy Drawable kt�ra umo�liwia pokazanie pi�ki na ekranie

};

