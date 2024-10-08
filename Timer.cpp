#include "Timer.h"

Timer::Timer(sf::RenderWindow& window, sf::FloatRect textRect) :
    Start(window.getSize().x - 550.f, window.getSize().y / 4.2f, xbox, ybox, "Start"),
    Stop(window.getSize().x - 550.f + (xbox + 50.f), window.getSize().y / 4.2f, xbox, ybox, "Stop"),
    Reset(window.getSize().x - 550.f + 2 * (xbox + 50.f), window.getSize().y / 4.2f, xbox, ybox, "Reset")
{
    font.loadFromFile("Coconut.ttf");
    StopWatch.setFont(font);
    StopWatch.setString(this->getter());
    StopWatch.setCharacterSize(60);
    // center the origin
    StopWatch.setOrigin(window.getSize().x / 1.3f, window.getSize().y / 4.2f);
    // set the position to the center of the window
    StopWatch.setPosition(sf::Vector2f(window.getSize().x + 450.f, window.getSize().y/1.5f ));
}
void Timer::reset()
{
    this->hour = 0;
    this->minute = 0;
    this->second = 0;
    this->last = 0;
}
void Timer::render(sf::RenderWindow& target)
{
    Start.render(target);
    Stop.render(target);
    Reset.render(target);

}
void Timer::update(sf::Vector2f mousePos,Timer& timer,Clock& time, sf::RenderWindow& window)
{
    StopWatch.setString(this->getter());

    std::string s;
    s += StopWatch.getString();
    std::cout << s<<'\n';

    Start.update(mousePos);
    Stop.update(mousePos);
    Reset.update(mousePos);
    if (Reset.getbuttonState())
    {
        timer.reset();
        Reset.setbuttonState(btn_idle);
    }
    if (Stop.getbuttonState())
    {
        Reset.setbuttonState(btn_idle);
        Start.setbuttonState(btn_idle);
    }
    if (Start.getbuttonState())
    {
        Reset.setbuttonState(btn_idle);
        Stop.setbuttonState(btn_idle);
        timer.update1(time);
    }
    window.draw(StopWatch);
    //return this->StopWatch;
}
sf::Text Timer::stopwatch()
{
    return StopWatch;
}

