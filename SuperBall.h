#pragma once
#include "Bonus.h"
class SuperBall : public Bonus
{
public:
	SuperBall();//konstruktor bezargumentowy
	~SuperBall();//destruktor
	SuperBall(int pos_X, int pos_Y, sf::Sprite sprite1);//konstruktor który przyjmuje dwie wartości tylu całkowitego oraz grafikę bonusu

	int help = 0;//zmienna pomocnicz typu całkowitego
	void Restart();//metoda typu pustego restartująca czas trwania bonusu
	void GetTime();//metoda typu zerowego obliczająca czas do zakończenia bonusu
	int Duration();//metoda typu całkowitego zwracająca czas trawnia bonusu
	int ElapsedTime();//metoda typu całkowitego zwracająca ile bonus już trwa
private:
	int duration = 10;//zmienna typu całkowitego przechowująca czas trwania bonusu
	sf::Clock superBallClock;//zmienna typu Clock licząca czas trwania bonusu
	sf::Time superBallElapsedTime;//zmienna typu Time przechowująca czas zegara 

};


