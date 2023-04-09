#pragma once

#include <iostream>
#include <vector>
#include <sstream>

#include "player.h"
#include "enemy.h"



/*
This acts as a game engine
*/

class Game {
    public:
        //Constructors, destructors
        Game();
        virtual ~Game();

        //Functions

        void pollEvents();
        void updateCollision();

        bool isGameOver() const;

        void renderGUI(sf::RenderTarget*);
        void updateGUI();

        void update();
        void render();
        

        //Accessors
        const bool getWindowIsOpen() const;

    private:
        //Variables
        sf::RenderWindow* window; //dynamic allocation - we want to delete it when we need to
        sf::VideoMode videoMode;
        sf::Event event;

        //Game logic
        int points;

        //Game objects
        Player player;
        Enemy enemy;

        sf::Font font;
        sf::Text guiText;
        sf::Text endGameText;

        //Functions
        void initVariable();
        void initWindow();
        void initFont();
        void initText();
};