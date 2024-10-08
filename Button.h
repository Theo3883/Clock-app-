#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include<windows.h>
enum button_state{btn_idle=0 , btn_hover,btn_pressed};
class Button
{
protected:
	button_state buttonState;
	sf::RectangleShape shape;
	sf::Font font;
	sf::Text text;
	
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	bool isPressed ;
public:
	Button();
	Button(float x, float y, float width, float height, std::string text);
	void render(sf::RenderWindow& target);
	virtual void update(const sf::Vector2f mousePos);
	void testfunction();
	bool getbuttonState();
	void setbuttonState(button_state newButtonState);
	bool IsPressed();
	std::string Text();
};

