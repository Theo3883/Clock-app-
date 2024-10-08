#pragma once
#include <SFML/Audio.hpp> // Include the SFML Audio module
#include "Button.h"
#include "Time.h"
class Alarm: public Button, public Clock
{
private:
	int hours;
	int minutes;
	int seconds;
	bool finish = false;
	Clock time;
	Button Stop;
	sf::Music music;
	const float xbox = 60;
	const float ybox = 40;

public:
	Alarm(int _hours, int _minutes, int _seconds, sf::RenderWindow& window);
	void update(Clock& time_general, sf::RenderWindow& window, sf::Vector2f mousePos);
};

