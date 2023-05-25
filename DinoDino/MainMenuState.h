#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameStates.h"
#include "CharacterSelecMenuState.h"
#include "Button.h"
#include "Icon.h"
#include "Musics.h"
#include "SelectionMenu.h"

class MainMenuState :
    public State
{
private:
    //variables
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;
    Musics* music;
    
 

    std::map<std::string, Button*> buttons;
    std::map<std::string, Icon*> icons;
    

    //functions
    void initvariables();
    void initBackground();
    void initIcons();
    void initFonts();
    void initKeybinds();
    void initButtons();
    // void initMusic();

public:
    //Constructors & Destructors
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys , std::stack<State*>* states);
    virtual ~MainMenuState();

    //Functions

    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(RenderTarget& target);
    void renderIcons(RenderTarget& target);
    void render(RenderTarget* target = NULL);
    
};
#endif

