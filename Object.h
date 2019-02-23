#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Object: public sf::Drawable
{
public:
	sf::Texture texture;//zmienna typu Texture przechowuj¹ca teksture obiektu
	sf::Sprite sprite;//zmienna typu Sprite przechowuj¹ca grafike obiektu
	sf::RectangleShape rect;//zmienna typu RectangleShape przechowuj¹ca kszta³t obiektu
	Object();//konstruktor bezparametrowy
	~Object() = default;//destruktor

	float Left();//metoda typu zmiennoprzecinkowego zwracaj¹ca lew¹ krawêdŸ obiektu
	float Right();//metoda typu zmiennoprzecinkowego zwracaj¹ca praw¹ krawêdŸ obiektu
	float Top();//metoda typu zmiennoprzecinkowego zwracaj¹ca górn¹ krawêdŸ obiektu
	float Bottom();//metoda typu zmiennoprzecinkowego zwracaj¹ca doln¹ krawêdŸ obiektu
	sf::Vector2f GetPosition(); //metoda typu Vector2f zwracaj¹ca pozycjê obiektu
	void SetPosition(int pos_X, int pos_Y);//metoda typu pustego ustawiaj¹ca poycjê obiektu

	const static int windowWidth = 1280;//statyczna sta³a reprezentuj¹ca szerokoœæ renderowaego okna
	const static int windowHeigth = 800;//statyczna sta³a reprezentuj¹ca wysokoœæ renderowaego okna

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;//metoda typu pustego nadpisauj¹ca metodê
                                                           //z klasy Drawable która umo¿liwia pokazanie pi³ki na ekranie

};

