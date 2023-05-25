//responsible for managing and displaying a collection of Profile objects. It provides functionality to add profiles, 
//sort them by their best scores, display the profiles, and retrieve the profile with the best score.

#pragma once
#include <vector>
#include <algorithm>
#include "Profile.h"

class Leaderboard {
public:
    void addProfile(Profile* profile); // Adds a Profile object to the leaderboard. The profile is passed as a pointer to the function.
    void sortProfiles();//Sorts the profiles in ascending order based on their best scores. The sorting is done using the std::sort algorithm from the <algorithm> library.
    void displayProfiles() const; // Displays the profiles in the leaderboard. It iterates over the profiles and calls the render function on each profile to render it on an SFML window or any other output method.
    Profile* getBestProfile() const; // Retrieves the profile with the best score from the leaderboard. It returns a pointer to the profile object.

private:
    std::vector<Profile*> profiles; //epresents the collection of Profile objects in the leaderboard. It is a vector of pointers to Profile objects, allowing dynamic addition and removal of profiles.
};

