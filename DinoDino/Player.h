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
    Player(float x, float y, sf::Texture& texture_sheet);
    virtual ~Player();

    //Functions

    virtual void update(const float& dt);
};
#endif // !PLAYER_H

