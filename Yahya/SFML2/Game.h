#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"
#include "LandScrnState.h"
using namespace std;

/*
	Class that acts as the game engine
	Wrapper class
*/
class Game
{
private:
	//Variable
	
	
	sf::RenderWindow* window;
	sf::Event event;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock dtClock;
	float dt;

	std::stack<State*>states;

	std::map<std::string, int> supportedKeys;


	// Initializion
	void initVariables();
	void initWindow();
	void initStates();
	void initKeys();

	//Game objects

public:

	//Constructors & Destructors

	Game();
	virtual ~Game();



	//Class FUnctions

	// Regular
	
	void endApplication();
	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	void run();
};
#endif // !GAME_H




