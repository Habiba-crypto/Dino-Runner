#include "GameStateProfile.h"
#include <iostream>

GameStateProfile::GameStateProfile() : currentState(State::MainMenu), currentProfile(nullptr) {
    font.loadFromFile("font.ttf");
    stateText.setFont(font);
    stateText.setCharacterSize(40);
    stateText.setFillColor(sf::Color::White);

    livesText.setFont(font);
    livesText.setCharacterSize(20);
    livesText.setFillColor(sf::Color::White);
}

void GameStateProfile::handleInput(sf::Event& event) {
    if (currentState == State::MainMenu) {
        // Handle main menu input
    }
    else if (currentState == State::Game) {
        // Handle game input
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            tracker.decreaseLives();
            if (tracker.isGameOver()) {
                currentState = State::GameOver;
            }
        }
    }
    else if (currentState == State::GameOver) {
        // Handle game over input
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            if (currentProfile != nullptr) {
                int score = 100; 
                currentProfile->setBestScore(score);
                leaderboard.addProfile(currentProfile);
                leaderboard.sortProfiles();
                Profile* bestProfile = leaderboard.getBestProfile();
                if (bestProfile != nullptr) {
                    std::cout << "Best Profile: " << bestProfile->getName() << ", Best Score: " << bestProfile->getBestScore() << std::endl;
                }
            }
            currentState = State::MainMenu;
            tracker.setLives(3);
        }
    }
    else if (currentState == State::Leaderboard) {
        // Handle leaderboard input
    }
}

void GameStateProfile::update() {
    if (currentState == State::MainMenu) {
        // Update main menu state
    }
    else if (currentState == State::Game) {
        // Update game state
    }
    else if (currentState == State::GameOver) {
        // Update game over state
    }
    else if (currentState == State::Leaderboard) {
        // Update leaderboard state
    }
}

void GameStateProfile::render(sf::RenderWindow& window) {
    window.clear();

    if (currentState == State::MainMenu) {
        // Render main menu state
        stateText.setString("Main Menu");
        window.draw(stateText);
    }
    else if (currentState == State::Game) {
        // Render game state
        stateText.setString("Game");
        livesText.setString("Lives: " + std::to_string(tracker.getLives()));
        stateText.setPosition(100, 100);
        livesText.setPosition(100, 150);
        window.draw(stateText);
        window.draw(livesText);
    }
    else if (currentState == State::GameOver) {
        // Render game over state
        stateText.setString("Game Over");
        stateText.setPosition(100, 100);
        window.draw(stateText);
    }
    else if (currentState == State::Leaderboard) {
        // Render leaderboard state
        stateText.setString("Leaderboard");
        stateText.setPosition(100, 100);
        window.draw(stateText);
    }

    window.display();
}
