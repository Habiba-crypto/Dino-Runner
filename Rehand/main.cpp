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
    sf::RenderWindow window(sf::VideoMode(800,600), "Character Selection Menu");
    CharacterSelectionMenu menu(window);

    // Load the image file
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.png")) {
        // Handle error loading image
    }
    // Create the sprite using the loaded texture
    sf::Sprite backgroundSprite(backgroundTexture);

    // Set the sprite to cover the entire window
    backgroundSprite.setScale(window.getSize().x / backgroundSprite.getLocalBounds().width,
        window.getSize().y / backgroundSprite.getLocalBounds().height);
    backgroundSprite.setPosition(1.f, 1.f);

    // Create the button box
    sf::RectangleShape buttonBox1(sf::Vector2f(150, 30));
    buttonBox1.setPosition(344, 150);
    buttonBox1.setFillColor(sf::Color::Green);
    buttonBox1.setOutlineThickness(2);
    buttonBox1.setOutlineColor(sf::Color::Black);
    sf::RectangleShape buttonBox2(sf::Vector2f(150, 30));
    buttonBox2.setPosition(344, 200);
    buttonBox2.setFillColor(sf::Color::Yellow);
    buttonBox2.setOutlineThickness(2);
    buttonBox2.setOutlineColor(sf::Color::Black);
    sf::RectangleShape buttonBox3(sf::Vector2f(150, 30));
    buttonBox3.setPosition(344, 250);
    buttonBox3.setFillColor(sf::Color::Magenta);
    buttonBox3.setOutlineThickness(2);
    buttonBox3.setOutlineColor(sf::Color::Black);
    sf::RectangleShape buttonBox4(sf::Vector2f(150, 30));
    buttonBox4.setPosition(344, 300);
    buttonBox4.setFillColor(sf::Color::Blue);
    buttonBox4.setOutlineThickness(2);
    buttonBox4.setOutlineColor(sf::Color::Black);

    // Create the character names
    sf::Font font;
    if (!font.loadFromFile("ARIBL0.ttf")) {
        // Handle error loading font
    }
    sf::Text character1Text("character1", font, 20);
    character1Text.setPosition(355, 150);
    sf::Text character2Text("character2", font, 20);
    character2Text.setPosition(355, 200);
    sf::Text character3Text("character3", font, 20);
    character3Text.setPosition(355, 250);
    sf::Text character4Text("character4", font, 20);
    character4Text.setPosition(355, 300);
    sf::Text mainmenu("Character Selection Menu", font, 30);
    mainmenu.setPosition(210, 70);
   

    // Main game loop
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            // Clear the window
            window.clear();

            // Draw the background sprite
            window.draw(backgroundSprite);

            // Draw the button box and character names       
            window.draw(buttonBox1);
            window.draw(buttonBox2);
            window.draw(buttonBox3);
            window.draw(buttonBox4);
            window.draw(character1Text);
            window.draw(character2Text);
            window.draw(character3Text);
            window.draw(character4Text);
            window.draw(mainmenu);



            // Update the window        
            window.display();


            // Update the window
            window.display();
            // Handle events
            menu.handleEvents();

            // Update menu state
            menu.update();
         

            // Draw menu
            menu.draw();

            // Display the window
            window.display();

            // Check if a character has been selected
            if (menu.getSelectedCharacter() != 0)
            {
                // Do something with the selected character (
                int selectedCharacter = menu.getSelectedCharacter();
                // ...

            }

        }

 
}
