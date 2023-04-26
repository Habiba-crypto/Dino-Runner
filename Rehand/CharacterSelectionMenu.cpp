#include "CharacterSelectionMenu.h"
using namespace std;
#include <iostream>

CharacterSelectionMenu::CharacterSelectionMenu(sf::RenderWindow& window)
    : m_window(window),
    m_selectedCharacter(0)
{
 
   
    // Set up title
    //m_title.setFont(m_font);
    m_title.setString("Select Your Character");
    m_title.setCharacterSize(1);
    m_title.setFillColor(sf::Color::White);
    m_title.setPosition(1.f, 1.f);

    // Set up character selection boxes
    m_character1Texture.loadFromFile("character1.png");
    m_character1.setTexture(m_character1Texture);
    m_character1.setPosition(60, 400);

    m_character2Texture.loadFromFile("character2.png");
    m_character2.setTexture(m_character2Texture);
    m_character2.setPosition(260.f, 425.f);

    m_character3Texture.loadFromFile("character3.png");
    m_character3.setTexture(m_character3Texture);
    m_character3.setPosition(425.f, 390.f);

    m_character4Texture.loadFromFile("character4.png");
    m_character4.setTexture(m_character4Texture);
    m_character4.setPosition(565.f, 385.f);
}

void CharacterSelectionMenu::draw()
{
    m_window.draw(m_background);
    m_window.draw(m_title);
    m_window.draw(m_character1);
    m_window.draw(m_character2);
    m_window.draw(m_character3);
    m_window.draw(m_character4);
}

void CharacterSelectionMenu::update()
{
    // Check if mouse is hovering over character selection boxes
    sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

    if (m_character1.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    {
        m_character1.setColor(sf::Color(200, 200, 200));
    }
    else
    {
        m_character1.setColor(sf::Color::White);
    }

    if (m_character2.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    {
        m_character2.setColor(sf::Color(200, 200, 200));
    }
    else
    {
        m_character2.setColor(sf::Color::White);
    }

    if (m_character3.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    {
        m_character3.setColor(sf::Color(200, 200, 200));
    }
    else
    {
        m_character3.setColor(sf::Color::White);
    }

    if (m_character4.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    {
        m_character4.setColor(sf::Color(200, 200, 200));
    }
    else
    {
        m_character4.setColor(sf::Color::White);
    }
}

void CharacterSelectionMenu::handleEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                // Check if mouse was clicked on a character selection box
                if (m_character1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    m_selectedCharacter = 1;
                }
                else if (m_character2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    m_selectedCharacter = 2;
                }
                else if (m_character3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    m_selectedCharacter = 3;
                }
                else if (m_character4.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    m_selectedCharacter = 4;
                }
            }
            break;
        }
    }
}

int CharacterSelectionMenu::getSelectedCharacter() const
{
    return m_selectedCharacter;
}
