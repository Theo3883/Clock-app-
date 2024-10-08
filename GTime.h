#include <string>
#include "DropDownList.h"
#include <chrono>
#include <iostream>
class GTime {
private:
	DropDownList*dll=nullptr;
	std::vector <std::string> states;
	void updatetime();
public:
	GTime(sf::RenderWindow& window, int xbox, int ybox);
	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderWindow& target);

};

