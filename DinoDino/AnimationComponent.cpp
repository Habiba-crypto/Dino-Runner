#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet)
	:sprite(sprite),texturesheet(texture_sheet),lastAnimation(NULL)
{
}

AnimationComponent::~AnimationComponent()
{
	for (auto& i : this->animations)
	{
		delete i.second;
	}
}

void AnimationComponent::addAnimation(const std::string key,
	float animation_Timer,
	int startframe_x, int startframe_y, int frames_x, int frames_y, int width, int height)
{
	this->animations[key] = new Animation(this->sprite, this->texturesheet
		, animation_Timer,
		startframe_x, startframe_y, frames_x, frames_y, width, height);
}

void AnimationComponent::play(const std::string key,const float& dt)
{
	if (this->lastAnimation != this->animations[key] )
	{
		if(this->lastAnimation == NULL)
			this->lastAnimation = this->animations[key];
		else 
		{
			this->lastAnimation->reset();
			this->lastAnimation = this->animations[key];
		}
		
	}
	this->animations[key]->sprite.setScale(5, 5);
	this->animations[key]->play(dt);
}
