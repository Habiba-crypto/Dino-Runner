#include "Game.h"

//Static Functions

//Initializer functions

//private functions


void Game::initVariables()
{
    this->window = NULL;
    this->fullscreen = false;
    this->dt = 0.f;
}

void Game::initWindow()
{
    /*Creates a window using options from file window init*/
    
    std::ifstream ifs("Config/window.init");
    this->videoModes = sf::VideoMode::getFullscreenModes();

    std::string title = " ## ";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    bool fullscreen = false;
    unsigned framerate_lim = 120;
    bool verticalsync_enabled = false;
    unsigned antialiasing_level = 0;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.height >> window_bounds.width;
        ifs >> fullscreen;
        ifs >> framerate_lim;
        ifs >> verticalsync_enabled;
        ifs >> antialiasing_level;

    }
    ifs.close();



    this->fullscreen = fullscreen;
    this->windowSettings.antialiasingLevel = antialiasing_level;
	if(this->fullscreen)
        this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen  , windowSettings);
    else
        this->window = new sf::RenderWindow(window_bounds, title,  sf::Style::Titlebar | sf::Style::Close, windowSettings);
        
    this->window->setFramerateLimit(framerate_lim);
    this->window->setVerticalSyncEnabled(verticalsync_enabled);
}

void Game::initKeys()
{
    std::ifstream ifs("Config/supported_keys.init");

    if (ifs.is_open()) {
        std::string key = "";
        int key_value = 0;
        while (ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }

    }

    ifs.close();



    ////Debug will move later
    //for (auto i : this->supportedKeys) {

    //    std::cout << i.first << " " << i.second << "\n";
    //}

}
//void Game::initMusic()
//{
//    this->music = new Musics();
//    //music->setfilepath("Resources/Music/main_theme.ogg");
//    music->isPlayed();
//    music->mute();
//
//
//
//}
void Game::initStates()
{
    this->states.push(new LandScrnState(this->window, &this->supportedKeys,&this->states));
    //this->states.push(new MainMenuState(this->window, &this->supportedKeys,&this->states));
    //this->states.push(new GameStates(this->window , &this->supportedKeys,&this->states));
}



//Constructors & Destructors
Game::Game()
{
	this->initWindow();
    this->initKeys();
    this->initStates();
 /*   this->initMusic();*/
    
}

Game::~Game()
{
	delete this->window;
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}



//Functions

void Game::endApplication()
{
    std::cout << "Ending Application" << "\n";
}
void Game::updateDt()
{
    //update the dt with the time it takes to update and render one frame 
    this->dt = this->dtClock.restart().asSeconds();

}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->event)) {

        if (this->event.type == Event::Closed)
            this->window->close();
    }
    

    window->clear();

}
void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);
        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }

    }//Apllication End
    else {
        this->endApplication();
        this->window->close();
    }
}

void Game::render()//visualising all the positions and points
{   /*
    @return void
    - clear old frame
    - render objects
    - display frame in window

    Render the game objects
    */
    //this->window->clear(Color(255, 0, 0, 255));
    
    //Render items
    
    if (!this->states.empty())
        this->states.top()->render();

    //Draw game objects
    this->window->display();
}


void Game::run()
{
    while (this->window->isOpen()) {
        this->updateDt();
        this->update();
        this->render();
    }
}
