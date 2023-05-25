// manages the player's lives and provides methods to access and update the number of lives,
//as well as determining if the game is over based on the remaining lives.
#pragma once

class Tracker {
public:
    Tracker(); //Default constructor for the Tracker class. It initializes the lives member variable to an initial value 
    int getLives() const; //Retrieves the current number of lives the player has.
    void setLives(int lives); //Sets the number of lives to the specified value.
    void decreaseLives(); //Decreases the number of lives by 1.
    bool isGameOver() const; //Checks if the player has no remaining lives (lives = 0), indicating that the game is over.

private:
    int lives; //Represents the number of lives the player has remaining. It is used to track the player's lives throughout the game
};
