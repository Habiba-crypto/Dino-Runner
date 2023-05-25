#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H


#include<iostream>
#include <string>
#include <map>


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Network.hpp>

class AnimationComponent
{
private:

	class Animation
	{
	public:
		//variables
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float animationTimer;
		float timer;
		int width;
		int height;
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;

		Animation(sf::Sprite& sprite,sf::Texture& texture_Sheet ,float animation_Timer,int startframe_x, int startframe_y, int frames_x, int frames_y, int width , int height)
			: sprite(sprite),textureSheet(texture_Sheet), animationTimer(animation_Timer), height(height) , width(width)
		{
			this->timer = 0.f;
			this->width = width; this->height = height;
			this->startRect = sf::IntRect(startframe_x * width, startframe_y * height, width, height);
			this->currentRect = this->startRect;
			this->endRect = sf::IntRect(frames_x * width, frames_y * height, width, height);
			this->sprite.setTexture(this->textureSheet , true);
			this->sprite.setTextureRect(this->startRect);
		}

		//FUnctions 
		void play(const float& dt)
		{
			//update timer 
			this->timer += 100.f *dt;
			if (this->timer >= this->animationTimer)
			{
				//reset timer
				this->timer = 0.f;
				//Animate
				if (this->currentRect != this->endRect)
				{
					this->currentRect.left += this->width;
				}
				else //Reset
				{
					this->currentRect.left = this->startRect.left;
				}
			}
			this->sprite.setTextureRect(this->currentRect);
		}

		
		void reset() 
		{
			this->timer = 0.f;
			this->currentRect = this->startRect;
		}

	};

	sf::Sprite& sprite;
	sf::Texture& texturesheet;
	std::map<std::string, Animation*> animations;
	Animation* lastAnimation;
public:
	AnimationComponent(sf::Sprite& sprite , sf::Texture& texture_sheet);
	virtual ~AnimationComponent();

	//FUnctions 
	void addAnimation(const std::string key ,
		float animation_Timer, int startframe_x, int startframe_y, int frames_x, int frames_y, int width, int height);



	void play(const std::string key,const float& dt);

};
#endif
