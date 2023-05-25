#include <SFML/Graphics.hpp>
#include "GameState.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    GameState gameState;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            gameState.handleInput(event);
        }

        gameState.update();

        window.clear();
        gameState.render(window);
        window.display();
    }

    return 0;
}
