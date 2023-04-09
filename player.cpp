#include "player.h"

//Initializer Functions
void Player::initVariable() {
    this->movementSpeed_ = 10.f;
    this->maxHealth_ = 100;
    this->health_ = maxHealth_;
    this->attackSpeedMax = 10.f;
    this->attackSpeed = this->attackSpeedMax;
}

void Player::initShape() {
    this->shape_.setPosition(sf::Vector2f(x_, y_));
    this->shape_.setSize(sf::Vector2f(30.f, 30.f));
    this->shape_.setFillColor(sf::Color::Green);
    this->shape_.setOutlineColor(sf::Color::Black);
    this->shape_.setOutlineThickness(2.f);
}

//Functions

void Player::updateWindowCollision(const sf::RenderTarget* target) {

    //check if the player is outside of the window
    if(this->shape_.getPosition().x < 0.f)
        this->shape_.setPosition(
            0.f, 
            this->shape_.getPosition().y
            );

    if(this->shape_.getPosition().x + this->shape_.getGlobalBounds().width >= target->getSize().x)
        this->shape_.setPosition(
            target->getSize().x - this->shape_.getGlobalBounds().width, 
            this->shape_.getPosition().y
            );

    if(this->shape_.getPosition().y <= 0.f)
        this->shape_.setPosition(
            this->shape_.getPosition().x, 
            0.f
            );

    if(this->shape_.getPosition().y + this->shape_.getGlobalBounds().height >= target->getSize().y)
        this->shape_.setPosition(
            this->shape_.getPosition().x, 
            target->getSize().y - this->shape_.getGlobalBounds().height
            );

}

void Player::updateInput() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and this->canAttack()) 
        this->missle.fireMissle(this->shape_.getGlobalBounds()); 

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->shape_.move(0.f, -this->movementSpeed_);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->shape_.move(-this->movementSpeed_, 0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->shape_.move(0.f, this->movementSpeed_);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->shape_.move(this->movementSpeed_, 0.f);

  
}

void Player::updateAttack() {
    if(this->attackSpeed < this->attackSpeedMax)
        this->attackSpeed += 0.5f;
}

void Player::updateObject(const sf::RenderTarget* target) {

    //Keyboard input
    this->updateInput();

    //Atack cooldown and missle update
    this->updateAttack();
    this->missle.updateObject(target);

    //Window bounds collision
    this->updateWindowCollision(target);

}

void Player::renderObject(sf::RenderTarget* target) {
    target->draw(this->shape_);
    //render the fired missles
    this->missle.renderObject(target);
}

//Checkers
const bool Player::canAttack() {
    
    if(this->attackSpeed >= this->attackSpeedMax){
        this->attackSpeed = 0.f;
        return true;
    }

    return false;
}

//Accessors

//Constructors, destructors
Player::Player(float x, float y) : GameObject(x, y) {
    this->initVariable();
    this->initShape();
}

Player::~Player() {

}