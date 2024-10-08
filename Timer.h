#pragma once
#include "Time.h"
#include "Button.h"
class Timer: public Button, public Clock
{
private: 

	const float xbox = 60;
	const float ybox = 40;
	Button Start;
	Button Stop;
	Button Reset;
	sf::Text StopWatch;
	sf::Font font;
public:
	Timer(sf::RenderWindow& window, sf::FloatRect textRect);
	void render(sf::RenderWindow& target);
	void reset();
	void update(sf::Vector2f mousePos, Timer& timer,Clock& time, sf::RenderWindow& window);
	sf::Text stopwatch();

};

