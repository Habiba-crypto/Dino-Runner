#pragma once

#include <SFML/Graphics.hpp>

class CharacterSelectionMenu
{
public:
    CharacterSelectionMenu(sf::RenderWindow& window);
    void draw();
    void update();
    void handleEvents();
    int getSelectedCharacter() const;

private:
    sf::RenderWindow& m_window;
    sf::RectangleShape m_background;
    sf::Text m_title;
    sf::Font m_font;
    sf::Sprite m_character1;
    sf::Sprite m_character2;
    sf::Sprite m_character3;
    sf::Sprite m_character4;
    int m_selectedCharacter;
    sf::Texture m_character1Texture;
    sf::Texture m_character2Texture;
    sf::Texture m_character3Texture;
    sf::Texture m_character4Texture;
};
