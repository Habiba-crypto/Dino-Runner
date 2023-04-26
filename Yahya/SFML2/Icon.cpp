#include "Icon.h"


//Constructors // Destructors
Icon::Icon(float x, float y, float width, float height , std::string path)
{
	//Button position and Size
	this->img.setPosition(sf::Vector2f(x, y));
	this->img.setSize(sf::Vector2f(width, height));
	if (!this->imgTexture.loadFromFile(path))
	{
		throw"ERROR::MainMenuSTATE::FAILED_TO_LOAD_Icon TEXTURE";
	}
	this->img.setTexture(&this->imgTexture);
}

Icon::~Icon()
{

}


//Functions
void Icon::update()
{

}

void Icon::render(sf::RenderTarget* target)
{
	target->draw(this->img);
}
