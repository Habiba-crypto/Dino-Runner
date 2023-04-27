#include "Musics.h"

bool Musics::musicState = true;
void Musics::initVariables()
{
	getfilepath();
	vol = 20;
	
	if (!this->muscBuffer.loadFromFile("Resources/Music/Dino-effect.ogg"))
	{
		throw"ERROR::MainMenuSTATE::FAILED_TO_LOAD_MUSIC BUFFER";
	}
	this->musc.setBuffer(this->muscBuffer);
	// set the playback position to 4 seconds
	sf::Time offset = sf::seconds(1);
	this->musc.setPlayingOffset(offset);
	// set the volume and loop
	this->musc.setVolume(vol);
	this->musc.setLoop(false);
	// start playing the sound
	this->musc.play();

	// stop the sound after 6 seconds
	//sf::sleep(sf::seconds(8));
	this->musc.stop();


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


