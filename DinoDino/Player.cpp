#include "Player.h"


//Intializer functions
void Player::initVariables()
{

}

void Player::initComponents()
{
	
}

//Constructor //Destructor
Player::Player(float x , float y , sf::Texture& texture_sheet)
{
	this->initVariables();
	


	this->setPosition(x, y);
	this->createHitboxComponent(this->sprite, 40.f, 40.f,55.f, 70.f);
	this->createMovementComponent(300.f, 8.f, 5.f);
	this->createAnimationComponent(texture_sheet);
	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 3, 0, 24, 24);
	this->animationComponent->addAnimation("MOVE", 10.f, 4, 0, 10, 0, 24, 24);
	this->animationComponent->addAnimation("JUMP", 10.f, 11, 0, 13, 0, 24, 24);
	this->animationComponent->addAnimation("DOWN", 10.f, 14, 0, 16, 0, 24, 24);
	this->animationComponent->addAnimation("DOWN", 10.f, 17, 0, 23, 0, 24, 24);
}

Player::~Player()
{

}

void Player::update(const float& dt)
{
	
	this->movementComponent->update(dt);

	if(this->movementComponent->getState(IDLE))
		this->animationComponent->play("IDLE",dt);

	else if(this->movementComponent->getState(MOVING))
	{
		this->animationComponent->play("MOVE", dt);
	}
		

	else if (this->movementComponent->getState(JUMP)) {
		this->animationComponent->play("JUMP", dt);
	}
		

	else if (this->movementComponent->getState(DOWN))
	{
		this->animationComponent->play("DOWN", dt);
	}
		

	else if (this->movementComponent->getState(DEAD))
	{
		this->animationComponent->play("DEAD", dt);

	}
		

	this->hitboxComponent->update();
}
