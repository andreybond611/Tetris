#include "Game.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Tetris.h"


Game::~Game()
{
	delete gameMode;
	gameMode = nullptr;
}

void Game::render()
{
	window.clear();

	gameMode->draw(&window);

	window.display();
}

void Game::update()
{
	gameMode->update(clock.restart());
}

void Game::processEvents()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			window.close();

		gameMode->processEvent(event);
	}
}

void Game::startGame()
{
	gameMode = new Tetris;
	clock.restart();
}

void Game::run()
{
    startGame();

    while (window.isOpen())
    {
        processEvents();

        update();

        render();
    }
}
