#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Musics
{

private:
	//variables
	sf::Sound musc;
	sf::SoundBuffer muscBuffer;

	static bool musicState;
	std::string filepath;
	float vol;


	
	
public:
	
	//Constructors //Destructors
	Musics();
	~Musics();

	//Functions
	void setfilepath(std::string name);
	std::string getfilepath();
	void initVariables();

	void isPlayed();
	void mute();




};
#endif

