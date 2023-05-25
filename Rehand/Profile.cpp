#include "Profile.h"

Profile::Profile() : name("visitor"), bestScore(0) {
    font.loadFromFile("font.ttf");
    nameText.setFont(font);
    nameText.setCharacterSize(20);
    nameText.setFillColor(sf::Color::White);
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
}

Profile::Profile(const std::string& name) : name(name), bestScore(0) {
    font.loadFromFile("font.ttf");
    nameText.setFont(font);
    nameText.setCharacterSize(20);
    nameText.setFillColor(sf::Color::White);
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
}

std::string Profile::getName() const {
    return name;
}

int Profile::getBestScore() const {
    return bestScore;
}

void Profile::setBestScore(int score) {
    bestScore = score;
}

void Profile::render(sf::RenderWindow& window) const {
    sf::Text nameText;   // Declare local sf::Text object for displaying the profile name
    sf::Text scoreText;  // Declare local sf::Text object for displaying the best score

    nameText.setString("Name: " + name);  // Set the content of the nameText
    nameText.setPosition(10, 10);  // Set the position of the nameText
    window.draw(nameText);  // Draw the nameText on the SFML window

    scoreText.setString("Best Score: " + std::to_string(bestScore));  // Set the content of the scoreText
    scoreText.setPosition(10, 40);  // Set the position of the scoreText
    window.draw(scoreText);  // Draw the scoreText on the SFML window
}
