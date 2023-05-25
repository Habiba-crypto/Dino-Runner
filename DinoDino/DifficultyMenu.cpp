#include "DifficultyMenu.h"

//Initializer functions
void DifficultyMenu::initvariables()
{

}

void DifficultyMenu::initBackground()
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

//void DifficultyMenu::initIcons()
//{
//	this->icons["DINO1"] = new Icon(400, 800, 150, 154, "Resources/Images/Players/character1.png");
//	this->icons["DINO2"] = new Icon(700, 800, 150, 154, "Resources/Images/Players/character2.png");
//	this->icons["DINO3"] = new Icon(1000, 800, 150, 154, "Resources/Images/Players/character3.png");
//	this->icons["DINO4"] = new Icon(1300, 800, 150, 154, "Resources/Images/Players/character4.png");
//
//
//}

void DifficultyMenu::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Cosmic Blaster.ttf"))
	{
		throw("ERROR:: MainMenuState:: COULD NOT LOAD FONT");
	}

}

void DifficultyMenu::initKeybinds()
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

void DifficultyMenu::initButtons()
{
	this->buttons["EASY"] = new Button(880, 160, 250, 80, &this->font, "Easy",
		sf::Color::Black, sf::Color(255, 0, 0, 150), sf::Color(20, 20, 20, 200));

	this->buttons["MEDIUM"] = new Button(880, 250, 250, 80, &this->font, "Medium",
		sf::Color::Black, sf::Color(255, 0, 0, 150), sf::Color(20, 20, 20, 200));

	this->buttons["HARD"] = new Button(880, 350, 250, 80, &this->font, "Hard",
		sf::Color::Black, sf::Color(255, 0, 0, 150), sf::Color(20, 20, 20, 200));

	this->buttons["RETURN"] = new Button(880, 450, 250, 80, &this->font, "Return to Main Menu",
		sf::Color::Black, sf::Color(255, 0, 0, 150), sf::Color(20, 20, 20, 200));

//	this->buttons["RETURN"] = new Button(880, 550, 250, 80, &this->font, "Return to Main Menu",
//		sf::Color(0, 255, 0, 200), sf::Color(255, 0, 0, 255), sf::Color(20, 20, 20, 200));
}

//void DifficultyMenu::initMusic()
//{
//	this->music = new Musics();
//	//music->setfilepath("Resources/Music/main_theme.ogg");
//	music->isPlayed();
//	music->mute();
//
//
//
//}

DifficultyMenu::DifficultyMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initvariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	//this->initIcons();
	//this->initMusic();



}

DifficultyMenu::~DifficultyMenu()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}

}




void DifficultyMenu::endState()
{
	std::cout << "Ending MainMenuState !" << "\n";
}

void DifficultyMenu::updateInput(const float& dt)
{
	////Mute
	////if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MUTE"))))
	////{
	////	this->music->mute();


	//}
	//Quit
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void DifficultyMenu::updateButtons()
{
	/*Update all the buttons in the state and thir functionality*/
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	// new game 
	//if (this->buttons["EASY"]->isPressed())
	//{
	//	this->states->pop();
	//	this->states->push(new GameStates(this->window, this->supportedKeys, this->states));

	//}

	if (this->buttons["RETURN"]->isPressed())
	{
		this->states->pop();
		this->states->push(new SelectionMenu(this->window, this->supportedKeys, this->states));

	}

	//Quit the game 
	//if (this->buttons["EXIT_STATE"]->isPressed())
	//{
	//	this->endState();
	//	this->quit = true;
	//}
}

void DifficultyMenu::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();

}

void DifficultyMenu::renderButtons(RenderTarget* target)
{

	for (auto& it : this->buttons)
	{
		it.second->render(*target);
	}
}

void DifficultyMenu::renderIcons(RenderTarget* target)
{

	for (auto& it : this->icons)
	{

		it.second->render(target);

	}

}

void DifficultyMenu::render(sf::RenderTarget* target)
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
