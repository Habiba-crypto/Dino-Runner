#ifndef HITBOXCOMPONENT_H
#define HITBOXCOMPONENT_H

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

class HitboxComponent
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;
	float offsetX, offsetY;
public:
	HitboxComponent(sf::Sprite& sprite,
		float offset_x, float offset_y,
		float width , float height);

	virtual ~HitboxComponent();

	//functions
	bool checkIntersect(const sf::FloatRect& fRect);
	void update();
	void render(sf::RenderTarget& target);
};
#endif

