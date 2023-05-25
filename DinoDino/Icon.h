#ifndef ICON_H
#define ICON_H


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class Icon
{
private:
	float Width;
	float Height;
	sf::RectangleShape img;
	sf::Texture imgTexture;
public:

	//Constructor //Destructor
	Icon(float x, float y, float width, float height , std::string path);
	~Icon();

	//Functions
	void setHeight(float H);
	void setWidth(float W);
	void update();
	void render(sf::RenderTarget* target);
};
#endif

