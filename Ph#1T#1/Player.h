#ifndef PLAYER_H
#define PLAYER_H



#include "Entity.h"
class Player :
    public Entity
{
private:
    //Variables


    //Intializer functions
    void initVariables();
    void initComponents();

public:
    //Constructor //Destructor
    Player(float x, float y, sf::Texture* texture);
    virtual ~Player();

    //Functions

};
#endif // !PLAYER_H

