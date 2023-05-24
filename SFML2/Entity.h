#ifndef ENTITY_H
#define ENTITY_H

#include "HitboxComponent.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"

using namespace sf;
using namespace std;

class Entity
{
private:
	void initVariables();
protected:
	
	sf::Sprite sprite;
	HitboxComponent* hitboxComponent;
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	
public:
	//Constructor //Destructor
	Entity();
	virtual ~Entity();

	// component function
	void setTexture(sf::Texture& texture);
	void createHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y,
		float width, float height);
	void createMovementComponent(const float maxVelocity, const float accelration, const float decelration);
	void createAnimationComponent( sf::Texture& texture_sheet);

	//Functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const float dir_x, const float dir_y, const float& dt);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};
#endif // !ENTITY_H
