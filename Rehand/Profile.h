//The Profile class is a representation of a player's profile in a game. 
//It stores information such as the player's name and their best score.
//The class provides methods to retrieve and update this information, 
//as well as a method to render the profile on an SFML window.
//encapsulates the profile information and provides methods to access and modify the data.
//It also provides a rendering function to display the profile visually using SFML.
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;

class Profile {
public:
    Profile();  // Default constructor
    Profile(const std::string& name);  // Constructor with name parameter

    std::string getName() const;  // Get the profile name
    int getBestScore() const;  // Get the best score
    void setBestScore(int score);  // Set the best score

    void render(sf::RenderWindow& window) const;  // Render the profile on an SFML window

private:
    std::string name;  // Profile name
    int bestScore;  // Best score

    sf::Text nameText;  // SFML text object for displaying the profile name
    sf::Text scoreText;  // SFML text object for displaying the best score
    sf::Font font;  // SFML font object for setting the font of the text objects
};
