#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Network.hpp>

enum movement_state {IDLE = 0,MOVING, JUMP ,DOWN , DEAD};
class MovementComponent
{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	float accelration;
	float decelration;

	sf::Vector2f velocity;


	//Intializers

public:
	MovementComponent(sf::Sprite& sprite,
		float maxVelocity, float accelration, float decelration );
	~MovementComponent();

	//Getters
	const sf::Vector2f& getVelocity();

	//Functions
	const bool getState(const short unsigned state) const;


	void move(const float dir_x, const float dir_y, const float& dt);
	void update(const float& dt);

};
#endif

