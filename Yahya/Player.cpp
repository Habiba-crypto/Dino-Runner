#include "Player.h"


//Intializer functions
void Player::initVariables()
{

}

void Player::initComponents()
{

}

//Constructor //Destructor
Player::Player(float x , float y , sf::Texture* texture)
{
	this->initVariables();
	this->initComponents();

	this->createSprite(texture);
	this->setPosition(x, y);

}

Player::~Player()
{

}
