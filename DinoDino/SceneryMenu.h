
#ifndef SceneryMenu_H
#define SceneryMenu_H

#include "GameStates.h"
#include "SelectionMenu.h"
#include "Button.h"
#include "Icon.h"
#include "Musics.h"

class SceneryMenu :
    public State
{
private:
    //variables
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;
    Musics* music;

    Icon* Dino1;


    std::map<std::string, Button*> buttons;
    std::map<std::string, Icon*> icons;


    //functions
    void initvariables();
    void initBackground();
    void initIcons();
    void initFonts();
    void initKeybinds();
    void initButtons();
    /*   void initMusic();*/

public:
    //Constructors & Destructors
    SceneryMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~SceneryMenu();

    //Functions

    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(RenderTarget* target = NULL);
    void renderIcons(RenderTarget* target = NULL);
    void render(RenderTarget* target = NULL);

};
#endif


