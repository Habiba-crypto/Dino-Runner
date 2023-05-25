#include "Leaderboard.h"
#include <iostream>
using namespace std;

void Leaderboard::addProfile(Profile* profile) {
    profiles.push_back(profile);
    // Add the provided profile to the leaderboard
}

void Leaderboard::sortProfiles() {
    std::sort(profiles.begin(), profiles.end(), [](const Profile* p1, const Profile* p2) {
        return p1->getBestScore() < p2->getBestScore();
        });
    // Sort the profiles in ascending order based on their best scores
}

void Leaderboard::displayProfiles() const {
    for (const Profile* profile : profiles) {
        std::cout << "Profile Name: " << profile->getName() << ", Best Score: " << profile->getBestScore() << std::endl;
        // Display the name and best score of each profile in the leaderboard
    }
}

Profile* Leaderboard::getBestProfile() const {
    if (!profiles.empty()) {
        return profiles.back();
        // Return the profile with the best score (the last profile in the sorted vector)
    }
    return nullptr;
    // If the leaderboard is empty, return nullptr
}
