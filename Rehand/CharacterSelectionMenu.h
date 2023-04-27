#pragma once

#include <SFML/Graphics.hpp>

class CharacterSelectionMenu
{
public:
    CharacterSelectionMenu(sf::RenderWindow *window);
    void draw();
    void update();
    void handleEvents();
    int getSelectedCharacter() const;
    void saveSelectedCharacterImage(const std::string&filename);
    bool run();
    std::string getSelectedCharacterFilename() const;



private:
    std::vector<std::string> m_characterFiles;
    int m_selectedIndex;
    sf::RenderWindow& m_window;
    sf::Texture m_backgroundTexture;
    sf::Sprite m_background;
    sf::RectangleShape m_character1Button;
    sf::RectangleShape m_character2Button;
    sf::RectangleShape m_character3Button;
    sf::RectangleShape m_character4Button;
    sf::Sprite m_character1;
    sf::Sprite m_character2;
    sf::Sprite m_character3;
    sf::Sprite m_character4;
    int m_selectedCharacter;
    sf::Texture m_character1Texture;
    sf::Texture m_character2Texture;
    sf::Texture m_character3Texture;
    sf::Texture m_character4Texture;
    sf::Font m_font;
    sf::Font font1;
    sf::Font font2;
    sf::Font font3;
    sf::Font font4;
    sf::Text m_title;
    sf::Text title1;
    sf::Text title2;
    sf::Text title3;
    sf::Text title4;
    sf::Text m_character1Text;
    sf::Text m_character2Text;
    sf::Text m_character3Text;
    sf::Text m_character4Text;
    bool m_character1Hovered;
    bool m_character2Hovered;
    bool m_character3Hovered;
    bool m_character4Hovered;

    void updateButtonHoverStates();
};
