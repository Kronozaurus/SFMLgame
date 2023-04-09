#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
Parent class for all game objects
*/

class GameObject {
    public:
        //Constructors, destructors
        GameObject(float = 0.f, float = 0.f);
        //Functions
        virtual void initVariable() = 0;
        virtual void initShape() = 0;
        virtual void updateObject(const sf::RenderTarget*) = 0;
        virtual void renderObject(sf::RenderTarget*) = 0;

        //Accessors

        //Friends
        friend class Player;
        friend class Enemy;
        friend class Game;
        friend class Missle;

    private:
        float x_;
        float y_;
        float movementSpeed_;
        float health_;
        float maxHealth_;
        sf::RectangleShape shape_;
};

