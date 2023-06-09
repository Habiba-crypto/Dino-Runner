#include "LandScrnState.h"


//Initializer functions
void LandScrnState::initvariables()
{

}

void LandScrnState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Background/landscrn.png"))
	{
		throw"ERROR::MainMenuSTATE::FAILED_TO_LOAD_landscrnTEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);
}

void LandScrnState::initIcons()
{
	
	this->icons["ENTER"] = new Icon(840, 880, 130, 130, "Resources/Images/Icons/enter.png");
	


}

void LandScrnState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Cosmic Blaster.ttf"))
	{
		throw("ERROR:: MainMenuState:: COULD NOT LOAD FONT");
	}

}

void LandScrnState::initKeybinds()
{

	std::ifstream ifs("Config/landScrnState_keybinds.init");

	if (ifs.is_open()) {
		std::string key1 = "";
		std::string key2 = "";
		while (ifs >> key1 >> key2)
		{
			this->keybinds[key1] = this->supportedKeys->at(key2);
		}

	}

	ifs.close();

}


void LandScrnState::initMusic()
{
	this->music = new Musics();
	music->setfilepath("Resources/Music/main_theme.ogg");
	music->isPlayed();
	music->mute();



}

LandScrnState::LandScrnState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initvariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	/*this->initButtons();*/
	this->initIcons();
	this->initMusic();



}

LandScrnState::~LandScrnState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}




void LandScrnState::endState()
{
	std::cout << "Ending MainMenuState !" << "\n";
	this->quit = true;
} 

void LandScrnState::updateInput(const float& dt)
{
	//Throw the main menu from the landscrn
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("ENTER"))))
	{
		this->states->push(new MainMenuState(this->window, this->supportedKeys, this->states));


	}
	//Quit
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}



void LandScrnState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	

}



void LandScrnState::renderIcons(RenderTarget* target)
{
	for (auto& it : this->icons)
	{
		it.second->render(target);
	}
}

void LandScrnState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);



	
	this->renderIcons(target);





}
