#pragma once
#include "Bonus.h"
class SuperBall : public Bonus
{
public:
	SuperBall();//konstruktor bezargumentowy
	~SuperBall();//destruktor
	SuperBall(int pos_X, int pos_Y, sf::Sprite sprite1);//konstruktor kt�ry przyjmuje dwie warto�ci tylu ca�kowitego oraz grafik� bonusu

	int help = 0;//zmienna pomocnicz typu ca�kowitego
	void Restart();//metoda typu pustego restartuj�ca czas trwania bonusu
	void GetTime();//metoda typu zerowego obliczaj�ca czas do zako�czenia bonusu
	int Duration();//metoda typu ca�kowitego zwracaj�ca czas trawnia bonusu
	int ElapsedTime();//metoda typu ca�kowitego zwracaj�ca ile bonus ju� trwa
private:
	int duration = 10;//zmienna typu ca�kowitego przechowuj�ca czas trwania bonusu
	sf::Clock superBallClock;//zmienna typu Clock licz�ca czas trwania bonusu
	sf::Time superBallElapsedTime;//zmienna typu Time przechowuj�ca czas zegara 

};


