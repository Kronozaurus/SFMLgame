#pragma once

#include "gameobject.h"
#include <iostream>

class Missle : public GameObject {
    public:
        //Constructors, destructors
        Missle();
        virtual ~Missle();

        //Functions
        virtual void initVariable() override;
        virtual void initShape() override;
        virtual void fireMissle(const sf::FloatRect&);
        virtual void updateObject(const sf::RenderTarget*) override;
        virtual void renderObject(sf::RenderTarget*) override;

        //Accessors

        //Friends
        friend class Game;
        friend class Player;

    private:
        std::vector<sf::RectangleShape> missles;

};