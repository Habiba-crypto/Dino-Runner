#ifndef GAMESTATES_H
#define GAMESTATES_H


#include "State.h"
#include "Musics.h"

class GameStates :
    public State
{

private :
    Entity player;
   

    //functions
    void initKeybinds();
    void initTextures();

public: 
    //Constructors & Destructors
    GameStates(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys , std::stack<State*>* states);
    virtual ~GameStates();

    //Functions

    

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target = NULL);
};
#endif // !GAMESTATES_H
