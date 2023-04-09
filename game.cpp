#include "game.h"


//Functions

void Game::pollEvents() {
    //Event polling
    while (this->window->pollEvent(this->event)) {
        switch(this->event.type){

            case sf::Event::Closed : {
                this->window->close();
                break;
            }

            case sf::Event::KeyPressed : {
                if(this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break; 
            }
        }
    }
}

void Game::updateCollision() {
    
    for(int i = 0; i < this->enemy.enemies.size(); i++){
        bool deleted = false;

        if(this->player.shape_.getGlobalBounds().intersects(this->enemy.enemies[i].getGlobalBounds())){
            this->player.health_ -= 10.f;
            this->points -= 50.f;
            deleted = true;
        }

        for(int j = 0; j < this->player.missle.missles.size(); j++) {
            if(this->player.missle.missles[j].getGlobalBounds().intersects(this->enemy.enemies[i].getGlobalBounds())) {
                this->player.missle.missles.erase(this->player.missle.missles.begin() + j);
                this->points += 10.f;
                deleted = true;
            }
        }

        if(deleted)
            this->enemy.enemies.erase(this->enemy.enemies.begin() + i);
    }
}

bool Game::isGameOver() const {
    if(this->player.health_ <= 0.f)
        return true;
    else
        return false;
}

void Game::renderGUI(sf::RenderTarget* target) {
    target->draw(this->guiText);
}

void Game::updateGUI() {
    std::stringstream stream;
    stream  << " - Points: " << this->points << "\n"
            << " - Health: " << this->player.health_ << " / " << this->player.maxHealth_;

    this->guiText.setString(stream.str());
}

void Game::update() {

    this->pollEvents();

    if(!this->isGameOver()){

        this->player.updateObject(this->window);
        this->enemy.updateObject(this->window);

        this->updateCollision();
        this->updateGUI();
    }
}


void Game::render() {

    //Clear old frame
    this->window->clear();

    //Draw game

    this->enemy.renderObject(this->window);
    this->player.renderObject(this->window);

    this->renderGUI(this->window);

    //render end game text
    if(this->isGameOver())
        this->window->draw(this->endGameText);

    //Display frame in window
    this->window->display();
}

//Accessors

const bool Game::getWindowIsOpen() const {
    return this->window->isOpen();
}

//Private functions

void Game::initVariable() {

    this->window = nullptr;
 
    //Game logic
    this->points = 0;
}

void Game::initWindow() {

    this->videoMode.height = 800;
    this->videoMode.width = 600;
    this->window = new sf::RenderWindow(this->videoMode, "Polibuda Invader", sf::Style::Titlebar | sf::Style::Close );
    this->window->setFramerateLimit(60);
}

void Game::initFont() {
    if(!this->font.loadFromFile("Fonts/comic.ttf")) {
        std::cout << "ERROR::INIT::FONT " << "\n";
    }
}

void Game::initText() {
    this->guiText.setFont(this->font);
    this->guiText.setFillColor(sf::Color::White);
    this->guiText.setOutlineColor(sf::Color::Black);
    this->guiText.setOutlineThickness(2.f);
    this->guiText.setCharacterSize(20);
    this->guiText.setPosition(sf::Vector2f(10, 20));

    //endgame text
    this->endGameText.setFont(this->font);
    this->endGameText.setFillColor(sf::Color::Red);
    this->endGameText.setOutlineColor(sf::Color::Black);
    this->endGameText.setOutlineThickness(2.f);
    this->endGameText.setCharacterSize(60);
    this->endGameText.setPosition(sf::Vector2f(120, 350));
    this->endGameText.setString("GAME OVER");
}

//Constructors, destructors

Game::Game() : player(300.f, 800.f) {
    this->initVariable();
    this->initWindow();
    this->initFont();
    this->initText();
}

Game::~Game() {
    delete this->window;
}