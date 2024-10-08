#pragma once
#include "Button.h"
enum button { timer_pressed, timer_unpressed };
class Button_grid
{
private:
	std::vector<Button*> buttons;
	int size;
	int last;
public:
	Button_grid();
	void add_button(Button* button);
	void update_buttons(const sf::Vector2f mousePos);
	void render_buttons(sf::RenderWindow& target);
	int buttonsState();
	void check_buttons_state();
};

