#include "Player.h"

Player::Player(sf::Texture* texturePtr)
    : m_velocity(0), m_isJumping(false), m_canDoubleJump(false), m_isDucking(false)
{
    m_sprite.setTexture(*texturePtr);
    m_sprite.setPosition(100, 100);
}

void Player::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::W) {
            if (!m_isJumping) {
                m_velocity = -800; // jump velocity
                m_isJumping = true;
            }
            else if (m_canDoubleJump) {
                m_velocity = -800; // double jump velocity
                m_canDoubleJump = false;
            }
        }
        else if (event.key.code == sf::Keyboard::S) {
            m_isDucking = true;
        }
    }
    else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::S) {
            m_isDucking = false;
        }
    }
}

void Player::update(float deltaTime)
{
    // apply gravity
    m_velocity += 2000 * deltaTime;

    // apply movement
    float moveAmount = m_velocity * deltaTime;
    m_sprite.move(0, moveAmount);

    // check for collision with ground
    if (m_sprite.getPosition().y + m_sprite.getGlobalBounds().height >= 600) {
        m_sprite.setPosition(m_sprite.getPosition().x, 600 - m_sprite.getGlobalBounds().height);
        m_velocity = 0;
        m_isJumping = false;
        m_canDoubleJump = true;
    }

    // apply ducking
    if (m_isDucking) {
        m_sprite.setScale(1, 0.5f);
        m_sprite.setPosition(m_sprite.getPosition().x, 600 - m_sprite.getGlobalBounds().height / 2.f);
    }
    else {
        m_sprite.setScale(1, 1);
        m_sprite.setPosition(m_sprite.getPosition().x, 600 - m_sprite.getGlobalBounds().height);
    }
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

void Player::setTexture(sf::Texture& texture)
{
    m_sprite.setTexture(texture);
}

void Player::openCharacterSelectionMenu()
{



        // load selected character texture
        sf::Texture* texturePtr = new sf::Texture();

        // create new window with selected character
        sf::RenderWindow window(sf::VideoMode(800, 600), "Selected Character");
        Player player(texturePtr);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                else {
                    player.handleInput(event);
                }
            }

            float deltaTime = 1.f / 60.f; // fixed time step of 1/60 second
            player.update(deltaTime);

            window.clear();
            player.draw(window);
            window.display();
        }
    
}