#include "Button.h"
Button::Button() 
{
	isPressed = 0;
	buttonState = btn_idle;
}
Button::Button(float x, float y, float width, float height, std::string text)
{
	isPressed = 0;
	font.loadFromFile("Coconut.ttf");
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(idleColor);
	this->font = font;
	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setCharacterSize(12);
	this->buttonState = btn_idle;
	this->idleColor = sf::Color(158, 152, 152, 100);
	this->hoverColor = sf::Color(77, 74, 74, 150);
	this->activeColor = sf::Color(43, 41, 41, 255);
	this->text.setFillColor(sf::Color::Red);
	sf::FloatRect textRect = this->text.getLocalBounds();
	this->text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->text.setPosition(this->shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f);
}
void Button::render(sf::RenderWindow& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}
void Button::update(sf::Vector2f mousePos)
{
	if(!this->isPressed)
		this->buttonState = btn_idle;
	if ((this->shape.getPosition().x < mousePos.x && mousePos.x < this->shape.getPosition().x + this->shape.getGlobalBounds().width)
		&& (this->shape.getPosition().y < mousePos.y && mousePos.y < this->shape.getPosition().y + this->shape.getGlobalBounds().height))
	{
		if (!this->isPressed)
			this->buttonState = btn_hover;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			switch (this->buttonState)
			{
			case btn_pressed:
				this->buttonState = btn_hover;
				isPressed = 0;
				break;
			case btn_hover:
				this->buttonState = btn_pressed;
				isPressed = 1;
				break;
			}
		}
	}
	switch (this->buttonState)
	{
	case btn_idle:
		this->shape.setFillColor(this->idleColor);
		break;
	case btn_hover:
		this->shape.setFillColor(this->hoverColor);
		break;
	case btn_pressed:
		this->shape.setFillColor(this->activeColor);
		break;
	}
}
void Button::testfunction()
{
	std::cout << this->buttonState << '\n';
	system("CLS");
}
bool Button::getbuttonState()
{
	if (buttonState == btn_pressed)
		return 1;
	return 0;
}
void Button::setbuttonState(button_state newButtonState)
{
	this->buttonState = newButtonState;
	if (newButtonState == btn_idle)
		isPressed = 0;
}

bool Button::IsPressed()
{
	return this->isPressed;
}

std::string Button::Text()
{
	return this->text.getString();
}
