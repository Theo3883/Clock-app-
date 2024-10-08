#include "Time.h"
#include <iostream>
#include <ctime>
#include <string>

// Clock and digital clock
Clock::Clock(): last(0) 
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    hour = ltm->tm_hour;
    minute = ltm->tm_min;
    second = ltm->tm_sec;
}
void Clock::update() {
    /*second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
            }
        }
    }*/
    time_t now = time(0);
    tm* ltm = localtime(&now);
    hour = ltm->tm_hour;
    minute = ltm->tm_min;
    second = ltm->tm_sec;
}
void Clock::update1(Clock& time)
{
    if (time.second - last == 0)
        return;
    last = time.second;
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
            }
        }
    }
}
void Clock::showTime() {
    std::cout << "Time: " << hour << ":" << minute << ":" << second<<"\n";
}
std::string Clock::getter()
{
    return std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
}
int Clock::minutes()
{
    return minute;
}
int Clock::seconds()
{
    return second;
}
int Clock::hours()
{
    return hour;
}

//Round Clock

CClock::CClock(int CLOCK_RADIUS, int sizex, int sizey) : radius(CLOCK_RADIUS), xsize(sizex/4.5f), ysize(sizey/2.2f){}
void CClock::numbers(sf::RenderWindow& window)
{
    sf::Font font;
    font.loadFromFile("arial.ttf"); // Replace with your font path
    for (int i = 0; i < 12; ++i) {
        sf::Text numbers(std::to_string(i + 1), font, 24);
        numbers.setFillColor(sf::Color::Black);
        numbers.setOrigin(numbers.getGlobalBounds().width / 2, numbers.getGlobalBounds().height / 2);
        float angle = (i - 2) * (360 / 12) * (3.14159265359 / 180); // Convert degrees to radians
        float x = xsize + (radius - 20) * cos(angle);
        float y = ysize + (radius - 20) * sin(angle);
        numbers.setPosition(x, y);
        window.draw(numbers);
    }
}
void CClock::clockface(sf::RenderWindow& window)
{
    sf::CircleShape clockFace(radius);
    clockFace.setFillColor(sf::Color(255, 255, 255, 50));
    clockFace.setOutlineThickness(2);
    clockFace.setOutlineColor(sf::Color::Black);
    clockFace.setOrigin(radius, radius);
    clockFace.setPosition(xsize, ysize);
    window.draw(clockFace);
}
void CClock::hour(sf::RenderWindow& window,Clock& time)
{
    sf::RectangleShape hourHand(sf::Vector2f(HOUR_HAND_LENGTH, 4));
    hourHand.setFillColor(sf::Color::Black);
    hourHand.setOrigin(0, 1);
    hourHand.setPosition(xsize, ysize);
    hourHand.setRotation((time.hours() * 30) + (time.minutes() * 0.5) - 90); // 30 degrees per hour, 0.5 degrees per minute
    window.draw(hourHand);
}
void CClock::minute(sf::RenderWindow& window, Clock& time)
{
    sf::RectangleShape minuteHand(sf::Vector2f(MINUTE_HAND_LENGTH, 4));
    minuteHand.setFillColor(sf::Color::Black);
    minuteHand.setOrigin(0, 0);
    minuteHand.setPosition(xsize, ysize);
    minuteHand.setRotation(time.minutes() * 6 - 90); // 6 degrees per minute
    window.draw(minuteHand);
}
void CClock::second(sf::RenderWindow& window,  Clock& time)
{
    sf::RectangleShape secondHand(sf::Vector2f(SECOND_HAND_LENGTH, 2));
    secondHand.setFillColor(sf::Color::Red);
    secondHand.setOrigin(0, 1);
    secondHand.setPosition(xsize, ysize);
    secondHand.setRotation(time.seconds() * 6 - 90); // 6 degrees per second
    window.draw(secondHand);
}
