#include "Button_grid.h"
Button_grid::Button_grid() :size(0),last(-1) {};
void Button_grid::add_button(Button* button)
{
	buttons.push_back(button);
	size++;
}
void Button_grid::update_buttons(const sf::Vector2f mousePos)
{
	for (int i = 0; i < size; i++)
	{
		buttons[i]->update(mousePos);
		if (buttons[i]->getbuttonState())
			last = i;
	}
}
void Button_grid::render_buttons(sf::RenderWindow& target)
{
	for (int i = 0; i < size; i++)
		buttons[i]->render(target);
}
int Button_grid::buttonsState()
{
	if(last!=-1 && buttons[last]->getbuttonState())
		return last;
	return -1;
}
void Button_grid::check_buttons_state()
{
	for (int i = 0; i < size; i++)
		if (i != last)
			buttons[i]->setbuttonState(btn_idle);
}