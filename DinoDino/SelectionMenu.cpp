#include "SelectionMenu.h"
#include "DifficultyMenu.h"
#include "SceneryMenu.h"

//#include "MainMenuState.h"

//Initializer functions
void SelectionMenu::initvariables()
{

}

void SelectionMenu::initBackground()
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
		throw"ERROR::SelectionMenu::FAILED_TO_LOAD_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);
}

void SelectionMenu::initIcons()
{
	this->icons["MOUSE1"] = new Icon(1000, 880, 130, 130, "Resources/Images/Icons/mouse1.png");
	this->icons["ENTER"] = new Icon(840, 880, 130, 130, "Resources/Images/Icons/enter.png");
	this->icons["UP"] = new Icon(690, 800, 130, 130, "Resources/Images/Icons/up.png");
	this->icons["DOWN"] = new Icon(690, 960, 130, 130, "Resources/Images/Icons/down.png");


}

void SelectionMenu::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Cosmic Blaster.ttf"))
	{
		throw("ERROR:: SelectionMenu:: COULD NOT LOAD FONT");
	}

}

void SelectionMenu::initKeybinds()
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

void SelectionMenu::initButtons()
{
	this->buttons["CHARACTERS"] = new Button(200, 480, 250, 80, &this->font, "Characters",
		sf::Color(0, 255, 0, 200), sf::Color(255, 0, 0, 255), sf::Color(20, 20, 20, 200));
	this->buttons["RETURN"] = new Button(200, 680, 250, 80, &this->font, "Return to Main Menu",
		sf::Color(0, 255, 0, 200), sf::Color(255, 0, 0, 255), sf::Color(20, 20, 20, 200));
	this->buttons["SCENERY"] = new Button(460, 480, 250, 80, &this->font, "Scenery",
		sf::Color(0, 255, 0, 200), sf::Color(255, 0, 0, 255), sf::Color(20, 20, 20, 200));
	this->buttons["DIFFICULTY"] = new Button(460, 680, 250, 80, &this->font, "Difficulty",
		sf::Color(0, 255, 0, 200), sf::Color(255, 0, 0, 255), sf::Color(20, 20, 20, 200));

}



void SelectionMenu::initMusic()
{
	this->music = new Musics();
	//music->setfilepath("Resources/Music/main_theme.ogg");
	music->isPlayed();
	music->mute();



}

SelectionMenu::SelectionMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initvariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initIcons();
	/*this->initMusic();*/



}

SelectionMenu::~SelectionMenu()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}




void SelectionMenu::endState()
{
	std::cout << "Ending SelectionMenu !" << "\n";
}

void SelectionMenu::updateInput(const float& dt)
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

void SelectionMenu::updateButtons()
{
	/*/ Update all the buttons in the state and thir functionality /*/
		for (auto& it : this->buttons)
		{
			it.second->update(this->mousePosView);
		}

	////Character selection 
	if (this->buttons["CHARACTERS"]->isPressed())
	{
		this->states->push(new CharacterSelecMenuState(this->window, this->supportedKeys, this->states));

	}

	//////Quit the game 
	if (this->buttons["DIFFICULTY"]->isPressed())
	{
		this->states->push(new DifficultyMenu(this->window, this->supportedKeys, this->states));

	}


	if (this->buttons["SCENERY"]->isPressed())
	{
		this->states->push(new SceneryMenu (this->window, this->supportedKeys, this->states));

	}


	if (this->buttons["RETURN"]->isPressed())
	{
		this->states->pop();
		this->states->push(new MainMenuState(this->window, this->supportedKeys, this->states));

	}
}

void SelectionMenu::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();

}

void SelectionMenu::renderButtons(RenderTarget* target)
{

	for (auto& it : this->buttons)
	{
		it.second->render(*target);
	}
}

void SelectionMenu::renderIcons(RenderTarget* target)
{
	for (auto& it : this->icons)
	{
		it.second->render(target);
	}
}

void SelectionMenu::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);



	this->renderButtons(target);
	this->renderIcons(target);

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
