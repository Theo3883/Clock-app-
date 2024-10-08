#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int CLOCK_RADIUS = 300;
const int HOUR_HAND_LENGTH = 150;
const int MINUTE_HAND_LENGTH = 200;
const int SECOND_HAND_LENGTH = 250;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Clock");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // Get current time
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int hours = ltm->tm_hour % 12; // Convert to 12-hour format
        int minutes = ltm->tm_min;
        int seconds = ltm->tm_sec;

        // Draw clock face
        sf::CircleShape clockFace(CLOCK_RADIUS);
        clockFace.setFillColor(sf::Color::White);
        clockFace.setOutlineThickness(2);
        clockFace.setOutlineColor(sf::Color::Black);
        clockFace.setOrigin(CLOCK_RADIUS, CLOCK_RADIUS);
        clockFace.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        window.draw(clockFace);

        // Draw hour hand
        sf::RectangleShape hourHand(sf::Vector2f(HOUR_HAND_LENGTH, 4));
        hourHand.setFillColor(sf::Color::Black);
        hourHand.setOrigin(0, 2);
        hourHand.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        hourHand.rotate((hours * 30) + (minutes * 0.5)); // 30 degrees per hour, 0.5 degrees per minute
        window.draw(hourHand);

        // Draw minute hand
        sf::RectangleShape minuteHand(sf::Vector2f(MINUTE_HAND_LENGTH, 4));
        minuteHand.setFillColor(sf::Color::Black);
        minuteHand.setOrigin(0, 2);
        minuteHand.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        minuteHand.rotate(minutes * 6); // 6 degrees per minute
        window.draw(minuteHand);

        // Draw second hand
        sf::RectangleShape secondHand(sf::Vector2f(SECOND_HAND_LENGTH, 2));
        secondHand.setFillColor(sf::Color::Red);
        secondHand.setOrigin(0, 1);
        secondHand.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        secondHand.rotate(seconds * 6); // 6 degrees per second
        window.draw(secondHand);

        window.display();
    }

    return 0;
}
