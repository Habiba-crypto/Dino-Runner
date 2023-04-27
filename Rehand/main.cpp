
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "CharacterSelectionMenu.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Character Selection Menu");
    CharacterSelectionMenu characterSelectionMenu(&window);

    // Main game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // handle events for character selection menu
        characterSelectionMenu.handleEvents();
        characterSelectionMenu.update();

        characterSelectionMenu.draw();

        window.display();

        if (characterSelectionMenu.getSelectedCharacter() > 0) {
            characterSelectionMenu.saveSelectedCharacterImage("selected_character.png");
            window.close();
        }

    
    }

    return 0;
}