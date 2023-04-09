#pragma once

#include "gameobject.h"
#include "missle.h"

/*
Player class
*/

class Player : public GameObject {
    public:
        //Constructors, destructors
        Player(float = 0.f, float = 0.f);
        virtual ~Player();

        //Functions
        virtual void initVariable() override;
        virtual void initShape() override;
        virtual void updateWindowCollision(const sf::RenderTarget*);
        virtual void updateInput();
        virtual void updateAttack();
        virtual void updateObject(const sf::RenderTarget*) override;
        virtual void renderObject(sf::RenderTarget*) override;

        //Checkers
        virtual const bool canAttack();

        //Accessors

        //Friends
        friend class Game;
        

    private:
        Missle missle;
        float attackSpeed;
        float attackSpeedMax;

};