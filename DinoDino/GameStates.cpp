#include "GameStates.h"

void GameStates::initBackground()
{
	//YAy

	if (!backgroundTexture.loadFromFile("Resources/Images/Background/1.png"))
	{
		throw "ERROR::MainMenuSTATE::FAILED_TO_LOAD_TEXTURE";
	}
	

	// Set the initial size and position of the background
	background.setSize(sf::Vector2f(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));

	background.setTexture(&backgroundTexture);


	// Set initial position and scroll speed
	backgroundPosition.x = 0.0f;
	scrollSpeed = 100.0f; // Adjust the scroll speed as desired
	 

}


void GameStates::initKeybinds()
{
	
	std::ifstream ifs("Config/GameState_keybinds.init");

	if (ifs.is_open()) {
		std::string key1 = "";
		std::string key2 = "";
		while (ifs >> key1 >> key2)
		{
			this->keybinds[key1] = this->supportedKeys->at(key2);
		}

	}

	ifs.close();
}

void GameStates::initTextures()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("Resources/Images/Players/sheets/DinoSprites_0.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE_SHEET";
	};
}

void GameStates::initPlayers()
{
	
	this->player = new Player(0, 0, this->textures["PLAYER_SHEET"]);
	
}

GameStates::GameStates(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initBackground(); 
	this->initKeybinds();
	this->initTextures();
	this->initPlayers();

}

GameStates::~GameStates()
{
	delete this->player;
	
}




void GameStates::gameLoop()
{
	
	sf::Clock clock;

	while (this->window->isOpen())
	{
		sf::Time deltaTime = clock.restart();

		// Update the background position based on the scroll speed and elapsed time
		float movement = this->scrollSpeed * deltaTime.asSeconds();
		this->backgroundPosition.x -= movement;

		// Reset the background position if it goes beyond the window width
		if (this->backgroundPosition.x < - float(this->window->getSize().x))
		{
			this->backgroundPosition.x = 0.0f;
		}

		// Set the new position of the background
		this->background.setPosition(this->backgroundPosition);

		// Clear the window
		
		// Draw the background
		this->window->draw(this->background);

		//Display the updated window
		this->window->display();

		this->initKeybinds();
		this->initTextures();
		this->initPlayers();
	}

}

void GameStates::updateInput(const float& dt)
{
	
	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->move( 0.f, -1.f , dt);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move( 0.f, 1.f, dt);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move( 1.f, 0.f, dt);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move( -1.f, 0.f, dt);

	//Quit
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void GameStates::update(const float& dt)
{
	
	this->updateMousePositions();
	this->updateInput(dt);
	this->player->update(dt);



}

void GameStates::render(sf::RenderTarget* target)
{
	this->gameLoop();
	if (!target)
		target = this->window;

	target->draw(this->background);
	
	this->player->render(*target);

}
