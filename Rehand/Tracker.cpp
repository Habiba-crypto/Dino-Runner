#include "Tracker.h"

Tracker::Tracker() : lives(3) {} 
//Default constructor for the Tracker class. It initializes the lives member variable to an initial value of 3, 
//indicating that the player starts with three lives

int Tracker::getLives() const {
    return lives;
}

void Tracker::setLives(int lives) {
    this->lives = lives;
}

void Tracker::decreaseLives() {
    lives--;
}

bool Tracker::isGameOver() const {
    return lives <= 0;
}
