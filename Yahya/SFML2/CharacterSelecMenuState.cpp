#include "CharacterSelecMenuState.h"

//Initializer functions
void CharacterSelecMenuState::initvariables()
{

}

void CharacterSelecMenuState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Background/CharSelectMenu.png"))
	{
		throw"ERROR::MainMenuSTATE::FAILED_TO_LOAD_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);
}

void CharacterSelecMenuState::initIcons()
{
	this->icons["DINO1"] = new Icon(60 , 400, 150, 154, "Resources/Images/Players/character1.png");
	this->icons["DINO2"] = new Icon(260, 425, 100, 126, "Resources/Images/Players/character2.png");
	this->icons["DINO3"] = new Icon(825, 890, 200, 169, "Resources/Images/Players/character3.png");
	this->icons["DINO4"] = new Icon(565, 385, 190, 172, "Resources/Images/Players/character4.png");


}

void CharacterSelecMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Cosmic Blaster.ttf"))
	{
		throw("ERROR:: MainMenuState:: COULD NOT LOAD FONT");
	}

}

void CharacterSelecMenuState::initKeybinds()
{

	std::ifstream ifs("Config/mainmenuState_keybinds.init");

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

void CharacterSelecMenuState::initButtons()
{
	this->buttons["CHARACTER1"] = new Button(344, 150, 150, 30, &this->font, "Character 1",
		sf::Color::Green, sf::Color(255, 0, 0, 150), sf::Color(20, 20, 20, 200));

	this->buttons["CHARACTER2"] = new Button(344, 200, 150, 30, &this->font, "Character 2",
		sf::Color::Yellow, sf::Color(255, 0, 0, 150), sf::Color(20, 20, 20, 200));

	this->buttons["CHARACTER3"] = new Button(344, 250, 150, 30, &this->font, "Character 3",
		sf::Color::Magenta, sf::Color(255, 0, 0, 150), sf::Color(20, 20, 20, 200));

	this->buttons["CHARACTER4"] = new Button(344, 300, 150, 30, &this->font, "Character 4",
		sf::Color::Blue, sf::Color(255, 0, 0, 150), sf::Color(20, 20, 20, 200));

}

void CharacterSelecMenuState::initMusic()
{
	this->music = new Musics();
	//music->setfilepath("Resources/Music/main_theme.ogg");
	music->isPlayed();
	music->mute();



}

CharacterSelecMenuState::CharacterSelecMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initvariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initIcons();
	this->initMusic();



}

CharacterSelecMenuState::~CharacterSelecMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}




void CharacterSelecMenuState::endState()
{
	std::cout << "Ending MainMenuState !" << "\n";
}

void CharacterSelecMenuState::updateInput(const float& dt)
{
	//Mute
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MUTE"))))
	{
		this->music->mute();


	}
	//Quit
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void CharacterSelecMenuState::updateButtons()
{
	/*Update all the buttons in the state and thir functionality*/
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
	
	// new game 
	if (this->buttons["CHARACTER1"]->isPressed())
	{
		
	
		//this->states->push(new GameStates(this->window, this->supportedKeys, this->states));

	}

	//Quit the game 
	//if (this->buttons["EXIT_STATE"]->isPressed())
	//{
	//	this->endState();
	//	this->quit = true;
	//}
}

void CharacterSelecMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();

}

void CharacterSelecMenuState::renderButtons(RenderTarget* target)
{

	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void CharacterSelecMenuState::renderIcons(RenderTarget* target)
{
	
	for (auto& it : this->icons)
	{
	
		it.second->render(target);
	
	}
	
}

void CharacterSelecMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);



	this->renderButtons(target);
	this->renderIcons(target);
	updateButtons();

	//only for debug
	/*sf::Text mouseText;
	mouseText.setPosition(this->mousePosView);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);*/



}
