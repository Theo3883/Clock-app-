#include "DropDownList.h"

DropDownList::DropDownList() : keytimeMax(1.f), keytime(0.f){};

DropDownList::DropDownList(std::vector<std::string> list, unsigned nrOfElem, unsigned default_index, sf::RenderWindow& window, int xbox, int ybox) :
	keytimeMax (1.f),keytime(0.f)
{
	for (auto i=0; i < nrOfElem; i++)
	{
		this->list.push_back(new Button(window.getSize().x / 1.5f, window.getSize().y / 7.f + i*ybox, xbox, ybox, list[i]));
	}
	this->activeElement = new Button(*this -> list[default_index]);
}

void DropDownList::update(const sf::Vector2f& mousePos)
{
	this->activeElement->update(mousePos);
	this->updateKeyTime();
	if (this->activeElement->IsPressed() && this->keytime)
	{
		if (this->showList)
			this->showList = false;
		else
			this->showList = true;
	}
	bool ok = 0;
	if(this->showList)
		for (auto i : this->list)
		{
			i->update(mousePos);
			if (i->IsPressed() && i->Text() != this->activeElement->Text() && ok)
			{
				std::cout << i<<"\n";
				for (auto j : this->list)
					if (j->Text() != i->Text() && j->Text() != this->activeElement->Text())
					{
						i->setbuttonState(btn_idle);
					}
			}
			ok = 1;
		}
}

void DropDownList::render(sf::RenderWindow& target)
{
	this->activeElement->render(target);
	if (this->showList)
		for (auto i : this->list)
		{
			i->render(target);
		}
}

const bool DropDownList::getKeyTime()
{
	if (this->keytime >= this->keytimeMax)
	{
		this->keytime = 0.f;
		return true;
	}
	return false;
}

void DropDownList::updateKeyTime()
{
	if (this->keytime < this->keytimeMax)
		this->keytime += 10.f * 1;
}
