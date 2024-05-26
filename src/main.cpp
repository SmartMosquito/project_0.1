#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include <cstdlib>
#include <ctime>
#include <Constants.h>



int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    Constants::HEIGHT=sf::VideoMode::getDesktopMode().height;
    Constants::WIDTH=sf::VideoMode::getDesktopMode().width;
    sf::RenderWindow window(sf::VideoMode(Constants::WIDTH,Constants::HEIGHT), "Snake Game", sf::Style::Fullscreen);
    window.setFramerateLimit(10);

    Snake snake;
    Food food;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
		    case sf::Keyboard::Escape:
			window.close();
                    case sf::Keyboard::Up:
                        if (snake.getDirection() != Down) snake.setDirection(Up);
                        break;
                    case sf::Keyboard::Down:
                        if (snake.getDirection() != Up) snake.setDirection(Down);
                        break;
                    case sf::Keyboard::Left:
                        if (snake.getDirection() != Right) snake.setDirection(Left);
                        break;
                    case sf::Keyboard::Right:
                        if (snake.getDirection() != Left) snake.setDirection(Right);
                        break;
                    default:
                        break;
                }
            }
        }

        snake.move();

        if (snake.checkCollision()) {
            snake = Snake();
	        food = Food();
        }

        if (snake.getSegments().front().x == food.getX() &&
            snake.getSegments().front().y == food.getY()) {
            snake.grow();
            food.respawn();
        }

        window.clear();

        // Draw snake
        for (const Segment& segment : snake.getSegments()) {
            sf::RectangleShape rectangle(sf::Vector2f(Constants::SIZE, Constants::SIZE));
            rectangle.setFillColor(sf::Color::Green);
            rectangle.setPosition(segment.x, segment.y);
            window.draw(rectangle);
        }

        // Draw food
        sf::RectangleShape foodShape(sf::Vector2f(Constants::SIZE, Constants::SIZE));
        foodShape.setFillColor(sf::Color::Red);
        foodShape.setPosition(food.getX(), food.getY());
        window.draw(foodShape);

        window.display();
    }

    return 0;
}
