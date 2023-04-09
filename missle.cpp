#include "missle.h"

//Initializer Functions

void Missle::initVariable() {
    this->movementSpeed_ = 5.f;
}

void Missle::initShape() {
    this->shape_.setSize(sf::Vector2f(2.f, 4.f));
    this->shape_.setFillColor(sf::Color::Yellow);
}

//Functions
void Missle::fireMissle(const sf::FloatRect& shooter) {
    this->shape_.setPosition(
        shooter.left + (shooter.width / 2),
        shooter.top
    );
    this->missles.emplace_back(shape_);
    std::cout << missles.size() << std::endl;
}

void Missle::updateObject(const sf::RenderTarget* target) {  

    for (int i = 0; i < this->missles.size(); i++){
        bool deleted = false;

        //move the missles upward
        this->missles[i].move(0.f, -this->movementSpeed_);

        //if out of window bounds delete the missle
        if(this->missles[i].getPosition().y < 0.f)
             deleted = true;
        
        //final delete (for multiple conditions)
        if(deleted)
            this->missles.erase(this->missles.begin() + i);
    }        
}

void Missle::renderObject(sf::RenderTarget* target) {
        for (auto &m : this->missles){
            target->draw(m);
        }
}

//Constructors, destructors

Missle::Missle() {
    this->initVariable();
    this->initShape();
}

Missle::~Missle() {

}