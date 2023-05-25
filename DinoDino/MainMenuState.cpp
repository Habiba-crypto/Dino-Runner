#include "MainMenuState.h"

//Initializer functions
void MainMenuState::initvariables()
{

}

void MainMenuState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x), 
			static_cast<float>(this->window->getSize().y)
		)
	);
	
	if (!this->backgroundTexture.loadFromFile("Resources/Images/Background/bg.png"))
	{
		throw"ERROR::MainMenuSTATE::FAILED_TO_LOAD_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initIcons()
{
	this->icons["MOUSE1"] = new Icon(1000, 880, 130, 130, "Resources/Images/Icons/mouse1.png");
	this->icons["ENTER"] = new Icon(840, 880, 130, 130, "Resources/Images/Icons/enter.png");
	this->icons["UP"] = new Icon(690, 800, 130, 130, "Resources/Images/Icons/up.png");
	this->icons["DOWN"] = new Icon(690, 960, 130, 130, "Resources/Images/Icons/down.png");


}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Cosmic Blaster.ttf"))
	{
		throw("ERROR:: MainMenuState:: COULD NOT LOAD FONT");
	}

}

void MainMenuState::initKeybinds()
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

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(200, 480, 250, 80, &this->font, "Play",
		sf::Color(0, 255, 0, 200), sf::Color(255, 0, 0, 255), sf::Color(20, 20, 20, 200));
	this->buttons["EXIT_STATE"] = new Button(200, 680, 250, 80, &this->font, "Exit",
		sf::Color(0, 255, 0, 200), sf::Color(255, 0, 0, 255), sf::Color(20, 20, 20, 200));
	this->buttons["ABOUT"] = new Button(460, 480, 250, 80, &this->font, "About",
		sf::Color(0, 255, 0, 200), sf::Color(255, 0, 0, 255), sf::Color(20, 20, 20, 200));
	this->buttons["Credits"] = new Button(460, 680, 250, 80, &this->font, "Credits",
		sf::Color(0, 255, 0, 200), sf::Color(255, 0, 0, 255), sf::Color(20, 20, 20, 200));

}

// void MainMenuState::initMusic()
// {
// 	this->music = new Musics();
// 	//music->setfilepath("Resources/Music/main_theme.ogg");
// 	music->isPlayed();
// 	music->mute();


	
// }

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys , std::stack<State*>* states)
	: State(window, supportedKeys , states)
{
	this->initvariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initIcons();
	//this->initMusic();

	
	
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for(it = this->buttons.begin();it!=this->buttons.end();++it)
	{
		delete it->second;
	}
}




void MainMenuState::endState()
{
	std::cout << "Ending MainMenuState !" << "\n";
}

void MainMenuState::updateInput(const float& dt)
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

void MainMenuState::updateButtons()
{
	/*Update all the buttons in the state and thir functionality*/
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	// new game 
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new SelectionMenu(this->window, this->supportedKeys, this->states));

	}

	//Quit the game 
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
		this->quit = true;
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();

}

void MainMenuState::renderButtons(RenderTarget& target)
{

	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::renderIcons(RenderTarget& target)
{
	for (auto& it : this->icons)
	{
		it.second->render(&target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	


	this->renderButtons(*target);
	this->renderIcons(*target);

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
