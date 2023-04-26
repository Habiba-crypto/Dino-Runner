#include "Musics.h"

bool Musics::musicState = true;
void Musics::initVariables()
{
	getfilepath();
	vol = 70;
	
	if (!this->muscBuffer.loadFromFile("Resources/Music/main_theme.ogg"))
	{
		throw"ERROR::MainMenuSTATE::FAILED_TO_LOAD_MUSIC BUFFER";
	}
	this->musc.setBuffer(this->muscBuffer);
}

void Musics::setfilepath(std::string name)
{
	filepath = name;

}

std::string Musics::getfilepath()
{
	return filepath;
}

Musics::Musics()
{
	initVariables();
	



	this->musc.setVolume(vol);
	
	this->musc.play();
	this->musc.setLoop(true);


}

Musics::~Musics()
{
}

void Musics::isPlayed()
{
	
	if (musicState == false) 
	{
		this->musc.pause();
	}
	else
		this->musc.play();
	
}

void Musics::mute()
{	
	
	isPlayed();
	musicState = !musicState;
	
}


