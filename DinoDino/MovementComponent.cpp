#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite,
	float maxVelocity , float accelration , float decelration ) : sprite(sprite),maxVelocity(maxVelocity), accelration(accelration),decelration(decelration)
{
	
}

MovementComponent::~MovementComponent()
{

}
const sf::Vector2f& MovementComponent::getVelocity()
{
	return this->velocity;
}



//Functions 

const bool MovementComponent::getState(const short unsigned state) const
{
	switch (state)
	{
	case IDLE:
		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
			return true;
		break;
	case MOVING:
		if (this->velocity.x != 0.f || this->velocity.y != 0.f)
			return true;
		break;
	case JUMP:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			return true;
		break;
	case DOWN:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			return true;
		break;

	}
	return false;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{	//acc
	this->velocity.x += this->accelration * dir_x;

	if (this->velocity.x > 0.f) //right checking 
	{
		
	}
	else if (this->velocity.x < 0.f) //left checking
	{
		
	}
	 
	this->velocity.y += this->accelration * dir_y;
	
}
//Functions
void MovementComponent::update(const float& dt)
{
	//decelration x 
	if (this->velocity.x > 0.f)//check for +ve x 
	{
		//Max velocity check
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		//+ve decelration in x
		this->velocity.x -= decelration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;


	}
	else if (this->velocity.x < 0.f)//check for -ve x 
	{
		//Max velocity check -ve
		if (this->velocity.x > -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;
		//-ve Decelration in x
		this->velocity.x += decelration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}

	//decelration y
	if (this->velocity.y > 0.f)//check for +ve y 
	{
		//Max velocity check
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		//+ve decelration in y
		this->velocity.y -= decelration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;


	}
	else if (this->velocity.y < 0.f)//check for -ve y 
	{
		//Max velocity check -ve
		if (this->velocity.y > -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;
		//-ve Decelration in y
		this->velocity.y += decelration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}
	//final 
	this->sprite.move(this->velocity * dt);//Use velocity
}
