#include "Alarm.h"
Alarm::Alarm(int _hours, int _minutes, int _seconds, sf::RenderWindow& window) : time(Clock(0, 0, 0)), hours(_hours), minutes(_minutes), seconds(_seconds),
Stop(window.getSize().x/2.f, window.getSize().y / 4.2f, xbox, ybox, "Stop")
{
	if (!music.openFromFile("alarm.ogg"))
		return; // error
	music.setVolume(10);
	music.setLoop(true);
}

void Alarm::update(Clock& time_general, sf::RenderWindow& window, sf::Vector2f mousePos)
{
	time.update1(time_general);
	//std::cout << time.getter()<<" "<< time.seconds()<<" "<< this->seconds<<    '\n';
	Stop.render(window);
	Stop.update(mousePos);
	if ((time.minutes() == this->minutes && time.seconds() == this->seconds && time.hours() == this->hours))
	{
		std::cout << "aici e";
		finish = true;
		music.play();
	}

}

