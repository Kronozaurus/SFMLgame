#include "enemy.h"

//Initializer Functions
void Enemy::initVariable() {
    this->movementSpeed_ = 2.f;
    this->maxHealth_ = 10;
    this->health_ = maxHealth_;
    this->enemySpawnTimerMax_ = 30.f;
    this->enemySpawnTimer_ = this->enemySpawnTimerMax_;
    this->maxEnemies_ = 10;
}

void Enemy::initShape() {
    this->shape_.setSize(sf::Vector2f(30.f, 30.f));
    this->shape_.setFillColor(sf::Color::Red);
    this->shape_.setOutlineColor(sf::Color::Black);
    this->shape_.setOutlineThickness(2.f);
}

//Functions
void Enemy::spawnObject(const sf::RenderTarget* target) {
    this->shape_.setPosition(
        static_cast<float>(rand() % static_cast<int>(target->getSize().x - this->shape_.getSize().x)),
        0.f //static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
    );
    //zeby zaimplementowac zycie i rozne predkosci trzeba przeniesc to do game i zrobic jako wektor enemies
    this->enemies.emplace_back(this->shape_); 
}

void Enemy::updateObject(const sf::RenderTarget* target) {

    //Timer for enemy spawning
    if(this->enemies.size() < this->maxEnemies_){

        if(this->enemySpawnTimer_ >= this->enemySpawnTimerMax_){
            this->spawnObject(target);
            this->enemySpawnTimer_ = 0.f;
        }
        else
            this->enemySpawnTimer_ += 1.f;

    }

    for (int i = 0; i < this->enemies.size(); i++){
        bool deleted = false;

        //move the enemies downward
        this->enemies[i].move(0.f, this->movementSpeed_);

        //if out of window bounds delete the enemy
        if(this->enemies[i].getPosition().y > target->getSize().y)
            deleted = true;
        
        //final delete (for multiple conditions)
        if(deleted)
            this->enemies.erase(this->enemies.begin() + i);
    }

}

void Enemy::renderObject(sf::RenderTarget* target) {
    for (auto &e : this->enemies){
        target->draw(e);
    }
}

//Accessors

//Constructors, destructors
Enemy::Enemy() {
    this->initVariable();
    this->initShape();
}

Enemy::~Enemy() {

}