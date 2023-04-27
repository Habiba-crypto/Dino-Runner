#include "CharacterSelectionMenu.h"
using namespace std;
#include <iostream>

CharacterSelectionMenu::CharacterSelectionMenu(sf::RenderWindow* window)
    : m_window(*window)
    , m_selectedCharacter(-1)
    , m_character1Hovered(false)
    , m_character2Hovered(false)
    , m_character3Hovered(false)
    , m_character4Hovered(false)
{
    if (!m_character1Texture.loadFromFile("character1.png"))
    {
        std::cerr << "Failed to load character1.png" << std::endl;
    }
    if (!m_character2Texture.loadFromFile("character2.png"))
    {
        std::cerr << "Failed to load character2.png" << std::endl;
    }
    if (!m_character3Texture.loadFromFile("character3.png"))
    {
        std::cerr << "Failed to load character3.png" << std::endl;
    }
    if (!m_character4Texture.loadFromFile("character4.png"))
    {
        std::cerr << "Failed to load character4.png" << std::endl;
    }

    //Background
    if (!m_backgroundTexture.loadFromFile("background.png"))
    {
        // handle error
    }
    m_background.setTexture(m_backgroundTexture);
    m_background.setScale(window->getSize().x / m_background.getLocalBounds().width,
        window->getSize().y / m_background.getLocalBounds().height);
    m_background.setPosition(1.f, 1.f);

    // Load font

    if (!m_font.loadFromFile("zerovelo.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }
    m_title.setFont(m_font);
    m_title.setString("Charcter Selection Menu");
    m_title.setCharacterSize(30);
    m_title.setFillColor(sf::Color::White);
    m_title.setPosition(150, 50);

    if (!font1.loadFromFile("arial.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }
    title1.setFont(font1);
    title1.setString("Charcter 1");
    title1.setCharacterSize(20);
    title1.setFillColor(sf::Color::White);
    title1.setPosition(355, 150);

    if (!font2.loadFromFile("arial.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }

    title2.setFont(font2);
    title2.setString("Charcter 2");
    title2.setCharacterSize(20);
    title2.setFillColor(sf::Color::White);
    title2.setPosition(355, 200);

    if (!font3.loadFromFile("arial.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }
    title3.setFont(font3);
    title3.setString("Charcter 3");
    title3.setCharacterSize(20);
    title3.setFillColor(sf::Color::White);
    title3.setPosition(355, 250);

    if (!font4.loadFromFile("arial.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }
    title4.setFont(font4);
    title4.setString("Charcter 4");
    title4.setCharacterSize(20);
    title4.setFillColor(sf::Color::White);
    title4.setPosition(365, 300);
    

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

    // Create the button box
    m_character1Button.setSize(sf::Vector2f(150, 30));
    m_character1Button.setPosition(344, 150);
    m_character1Button.setFillColor(sf::Color::Green);
    m_character1Button.setOutlineThickness(2);
    m_character1Button.setOutlineColor(sf::Color::Black);
    m_character1Text.setFont(font1);
    m_character1Text.setString("Character 1");
    m_character1Text.setCharacterSize(20);
    m_character1Text.setPosition(365, 150);
    

    m_character2Button.setSize(sf::Vector2f(150, 30));
    m_character2Button.setPosition(344, 200);
    m_character2Button.setFillColor(sf::Color::Yellow);
    m_character2Button.setOutlineThickness(2);
    m_character2Button.setOutlineColor(sf::Color::Black);
    m_character2Text.setFont(font2);
    m_character2Text.setString("Character 2");
    m_character2Text.setCharacterSize(20);
    m_character2Text.setPosition(365, 200);
    

    m_character3Button.setSize(sf::Vector2f(150, 30));
    m_character3Button.setPosition(344, 250);
    m_character3Button.setFillColor(sf::Color::Magenta);
    m_character3Button.setOutlineThickness(2);
    m_character3Button.setOutlineColor(sf::Color::Black);
    m_character3Text.setFont(font3);
    m_character3Text.setString("Character 3");
    m_character3Text.setCharacterSize(20);
    m_character3Text.setPosition(365, 250);

    m_character4Button.setSize(sf::Vector2f(150, 30));
    m_character4Button.setPosition(344, 300);
    m_character4Button.setFillColor(sf::Color::Blue);
    m_character4Button.setOutlineThickness(2);
    m_character4Button.setOutlineColor(sf::Color::Black);
    m_character4Text.setFont(font4);
    m_character4Text.setString("Character 4");
    m_character4Text.setCharacterSize(20);
    m_character4Text.setPosition(365, 300);
}


void CharacterSelectionMenu::draw()
{
    m_window.draw(m_background);
    m_window.draw(m_title);
    m_window.draw(title1);
    m_window.draw(title2);
    m_window.draw(title3);
    m_window.draw(title4);

    m_window.draw(m_character1Button);
    m_window.draw(m_character2Button);
    m_window.draw(m_character3Button);
    m_window.draw(m_character4Button);

    m_window.draw(m_character1Text);
    m_window.draw(m_character2Text);
    m_window.draw(m_character3Text);
    m_window.draw(m_character4Text);

    if (m_character1Hovered)
    {
        m_window.draw(m_character1);
    }
    if (m_character2Hovered)
    {
        m_window.draw(m_character2);
    }
    if (m_character3Hovered)
    {
        m_window.draw(m_character3);
    }
    if (m_character4Hovered)
    {
        m_window.draw(m_character4);
    }

    
}

void CharacterSelectionMenu::update()
{
    updateButtonHoverStates();
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
                if (m_character1Hovered)
                {
                    m_selectedCharacter = 1;
                }
                else if (m_character2Hovered)
                {
                    m_selectedCharacter = 2;
                }
                else if (m_character3Hovered)
                {
                    m_selectedCharacter = 3;
                }
                else if (m_character4Hovered)
                {
                    m_selectedCharacter = 4;
                }
            }
            break;
        default:
            break;
        }
    }
}

int CharacterSelectionMenu::getSelectedCharacter() const
{
    return m_selectedCharacter;
}

void CharacterSelectionMenu::saveSelectedCharacterImage(const std::string& filename)
{
    sf::Texture texture;
    switch (m_selectedCharacter)
    {
    case 1:
        texture = m_character1Texture;
        break;
    case 2:
        texture = m_character2Texture;
        break;
    case 3:
        texture = m_character3Texture;
        break;
    case 4:
        texture = m_character4Texture;
        break;
    default:
        return;
    }

    sf::Image image = texture.copyToImage();
    if (!image.saveToFile(filename))
    {
        std::cerr << "Failed to save image to " << filename << std::endl;
    }
}
bool CharacterSelectionMenu::run()
{
    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
                return false;
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    m_selectedIndex--;
                    if (m_selectedIndex < 0) {
                        m_selectedIndex = m_characterFiles.size() - 1;
                    }
                    // update menu items
                    // ...
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    m_selectedIndex++;
                    if (m_selectedIndex >= m_characterFiles.size()) {
                        m_selectedIndex = 0;
                    }
                    // update menu items
                    // ...
                }
                else if (event.key.code == sf::Keyboard::Enter) {
                    m_window.close();
                    return true;
                }
            }
        }

        m_window.clear();
        // draw menu items
        // ...
        m_window.display();
    }

    return false;
}
std::string CharacterSelectionMenu::getSelectedCharacterFilename() const
{
    if (m_selectedIndex >= 0 && m_selectedIndex < m_characterFiles.size()) {
        return m_characterFiles[m_selectedIndex];
    }
    else {
        return "";
    }
}
void CharacterSelectionMenu::updateButtonHoverStates()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

    m_character1Hovered = m_character1Button.getGlobalBounds().contains(mousePos.x, mousePos.y);
    m_character2Hovered = m_character2Button.getGlobalBounds().contains(mousePos.x, mousePos.y);
    m_character3Hovered = m_character3Button.getGlobalBounds().contains(mousePos.x, mousePos.y);
    m_character4Hovered = m_character4Button.getGlobalBounds().contains(mousePos.x, mousePos.y);
}


