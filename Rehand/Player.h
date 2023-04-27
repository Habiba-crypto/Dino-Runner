#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(sf::Texture* texture);
    void handleInput(sf::Event& event);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void setTexture(sf::Texture& texture);
    void openCharacterSelectionMenu();

private:
    sf::Sprite m_sprite;
    float m_velocity;
    bool m_isJumping;
    bool m_canDoubleJump;
    bool m_isDucking;
};