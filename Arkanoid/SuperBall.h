#pragma once
#include "Bonus.h"
class SuperBall : public Bonus
{
public:
	SuperBall();//konstruktor bezargumentowy
	~SuperBall();//destruktor
	SuperBall(int pos_X, int pos_Y, sf::Sprite sprite1);//konstruktor który przyjmuje dwie wartoœci tylu ca³kowitego oraz grafikê bonusu

	int help = 0;//zmienna pomocnicz typu ca³kowitego
	void Restart();//metoda typu pustego restartuj¹ca czas trwania bonusu
	void GetTime();//metoda typu zerowego obliczaj¹ca czas do zakoñczenia bonusu
	int Duration();//metoda typu ca³kowitego zwracaj¹ca czas trawnia bonusu
	int ElapsedTime();//metoda typu ca³kowitego zwracaj¹ca ile bonus ju¿ trwa
private:
	int duration = 10;//zmienna typu ca³kowitego przechowuj¹ca czas trwania bonusu
	sf::Clock superBallClock;//zmienna typu Clock licz¹ca czas trwania bonusu
	sf::Time superBallElapsedTime;//zmienna typu Time przechowuj¹ca czas zegara 

};


