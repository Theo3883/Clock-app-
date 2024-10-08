#include <SFML/Graphics.hpp>
#include "Time.h"
#include <iostream>
#include <string>
#include<windows.h>
#include "Timer.h"
#include "Button_grid.h"
#include "Alarm.h"
#include "GTime.h"
button buttonState;
void update_round_clock(CClock watch, sf::RenderWindow& window,Clock time);
//std::vector <Button*> lower_buttons;

int main()
{
    int xbox = 60, ybox = 40;
    Clock time;
    const int CLOCK_RADIUS = 150;
    sf::RenderWindow window(sf::VideoMode(1200, 900), "App");
    sf::Texture texture;
    if (!texture.loadFromFile("background.jpg"))
        return -1;
    sf::Sprite sprite(texture);

    sf::Font font;
    if (!font.loadFromFile("Coconut.ttf"))
    {
        std::cout << "Font error";
        return -1;
    }

    sf::Text text;
    text.setFont(font);
    text.setString(time.getter()); 
    text.setCharacterSize(60); 
    text.setFillColor(sf::Color::Red); 

    // center the origin
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    // set the position to the center of the window
    text.setPosition(sf::Vector2f(window.getSize().x / 4.5f, window.getSize().y / 6.5f));

    CClock watch(CLOCK_RADIUS,window.getSize().x, window.getSize().y);

    //lower_buttons.push_back(new  Button(window.getSize().x / 7.f, window.getSize().y / 1.2f, xbox, ybox, "Timer")); ///make the buttons
    Button_grid lower_buttons;
    lower_buttons.add_button(new Button(window.getSize().x / 7.f, window.getSize().y / 1.2f, xbox, ybox, "Timer"));
    lower_buttons.add_button(new  Button(window.getSize().x / 5.f, window.getSize().y / 1.2f, xbox, ybox, "Alarm"));
    lower_buttons.add_button(new  Button(window.getSize().x / 3.9f, window.getSize().y / 1.2f, xbox+30, ybox, "Time Zoned"));

    Timer timercount(window,textRect);
    timercount.reset();

    Alarm alarma(0,0,5,window);

    /*sf::Text Timer;
    Timer.setFont(font);
    Timer.setString(timercount.getter());
    Timer.setCharacterSize(60);
    //text.setFillColor(sf::Color::Red);

    // center the origin
    Timer.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    // set the position to the center of the window
    Timer.setPosition(sf::Vector2f(window.getSize().x / 1.3f, window.getSize().y / 2.f));*/
    GTime global_times(window, 200, 50);

    while (window.isOpen())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);

        update_round_clock(watch, window, time);

        lower_buttons.render_buttons(window); ///render the buttons
        sf::Vector2f mousePosFloat(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        lower_buttons.update_buttons(mousePosFloat); ///update the buttons

        text.setString(time.getter());
        time.update();
        int index = 0;
        //sf::Text Test;
        switch (lower_buttons.buttonsState())
        {
        case 0:   /// button timer
            lower_buttons.check_buttons_state();
            //Timer.setString(timercount.getter());
            timercount.update(mousePosFloat,timercount,time,window);
            timercount.render(window);

            break;
        case 1:
            lower_buttons.check_buttons_state();
            alarma.update(time,window,mousePosFloat);

            break;
        case 2:
            lower_buttons.check_buttons_state();
            global_times.update(mousePosFloat);
            global_times.render(window);
			break;
        default:
            break;
        }
        /*timercount.update1(time);
        Timer.setString(timercount.getter());

        window.draw(Timer);*/
        window.draw(text);
        window.display();
        //std::cout<<time.getter()<<'\n';
    }
    return 0;
}
void update_round_clock(CClock watch, sf::RenderWindow& window, Clock time)
{
    //drow the clock
    watch.clockface(window);
    watch.numbers(window);
    watch.hour(window, time);
    watch.minute(window, time);
    watch.second(window, time);
}