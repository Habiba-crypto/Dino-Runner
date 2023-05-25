#ifndef GAMESTATES_H
#define GAMESTATES_H


#include "State.h"
#include "Musics.h"
#include "Player.h"


class GameStates :
    public State
{

private :

    Player* player;
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Sprite backgroundSprite;
    float scrollSpeed;
    sf::Clock clock;
    sf::Vector2f backgroundPosition;
    


    //functions
    void initBackground();
    void initKeybinds();
    void initTextures();
    void initPlayers();
    

public: 
    //Constructors & Destructors
    GameStates(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys , std::stack<State*>* states);
    virtual ~GameStates();


    //Functions

    
    void gameLoop();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target = NULL);
};
#endif // !GAMESTATES_H
