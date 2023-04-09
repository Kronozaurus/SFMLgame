#pragma once

#include "gameobject.h"

/*
Enemy class
*/

class Enemy : public GameObject {
    public:
        //Constructors, destructors
        Enemy();
        virtual ~Enemy();

        //Functions
        virtual void initVariable() override;
        virtual void initShape() override;
        virtual void spawnObject(const sf::RenderTarget*);
        virtual void updateObject(const sf::RenderTarget*) override;
        virtual void renderObject(sf::RenderTarget*) override;

        //Accessors

        //Friends
        friend class Game;
        
    private:
        float enemySpawnTimer_;
        float enemySpawnTimerMax_;
        int maxEnemies_;
        std::vector<sf::RectangleShape> enemies;
};