#include "GameStates.h"

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

}

GameStates::GameStates(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
}

GameStates::~GameStates()
{

}




void GameStates::updateInput(const float& dt)
{
	
	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player.move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player.move(dt, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player.move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player.move(dt, -1.f, 0.f);

	//Quit
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void GameStates::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->player.update(dt);


}

void GameStates::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player.render(target);

}
