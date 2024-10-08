#pragma once
#include "SFML/Graphics.hpp"
#include "Button.h"
class DropDownList
{
private:
	float keytime;
	float keytimeMax;
	Button* activeElement;
	std::vector<Button*> list;
	bool showList = false;
public:
	DropDownList();
	DropDownList(std::vector<std::string> list, unsigned nrOfElem, unsigned default_index, sf::RenderWindow& window, int xbox, int ybox);
	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderWindow& target);
	const bool getKeyTime();
	void updateKeyTime();

};

