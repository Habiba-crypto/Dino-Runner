#pragma once

#include <SFML/Graphics.hpp>
#include "Profile.h"
#include "Leaderboard.h"
#include "Tracker.h"

enum class State {
    MainMenu,       // Main menu state
    Game,           // Gameplay state
    GameOver,       // Game over state
    Leaderboard     // Leaderboard state
};

class GameState {
public:
    GameState();  // Constructor

    void handleInput(sf::Event& event);  // Handles input events
    void update();  // Updates the game state
    void render(sf::RenderWindow& window);  // Renders the game state

private:
    State currentState;  // Current state of the game
    Profile* currentProfile;  // Pointer to the current profile
    Leaderboard leaderboard;  // Leaderboard instance
    Tracker tracker;  // Tracker instance
    sf::Text stateText;  // Text object for displaying the current state
    sf::Text livesText;  // Text object for displaying the remaining lives
    sf::Font font;  // Font object for text rendering
};
