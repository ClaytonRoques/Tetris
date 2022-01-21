#include "Game.h"
#include "iostream"

using std::cout;

//Private functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 640;
	this->videoMode.width = 480;
	this->window = new sf::RenderWindow(this->videoMode, "Tetris", sf::Style::Titlebar | sf::Style::Close);
}

//Constructors // Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}


//Acceessors
const bool Game::running() const
{
	return this->window->isOpen();
}


// Functions
void Game::pollEvents()
{
	// Event polling
	while (this->window->pollEvent(this->e))
	{
		switch (this->e.type)
		{
		case sf::Event::Closed:
			//cout << "Close command received\n";
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->e.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		case sf::Event::LostFocus:
			//cout << "Lost focus\n";
			break;
		case sf::Event::GainedFocus:
			cout << "Gained focus\n";
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	/*
		- clear old frame
		- render objects
		- display frame in window

		Renders the game objects
	*/
	this->window->clear(sf::Color::Black);
	
	//Draw game objects

	this->window->display();
}