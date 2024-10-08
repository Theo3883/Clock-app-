#include "GTime.h"

void GTime::updatetime()
{
	
}

GTime::GTime(sf::RenderWindow& window, int xbox, int ybox)
{
	states.push_back("States");
	for (const auto& tz : std::chrono::get_tzdb().zones)
		states.push_back(static_cast<std::string>(tz.name()));
	this->dll = new DropDownList(states, states.size(), 0, window, xbox, ybox);
				

}

void GTime::update(const sf::Vector2f& mousePos)
{
	this->dll->update(mousePos);
	updatetime();
}

void GTime::render(sf::RenderWindow& target)
{
	this->dll->render(target);
}

