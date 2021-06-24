#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    sf::VideoMode videoMode{visiblePlayfieldSize.x * squareSize, visiblePlayfieldSize.y * squareSize};
    
    sf::RenderWindow window(videoMode, "Tetris");

    Game::getGame().startGame();
	
    while (window.isOpen())
    {
        auto game = Game::getGame().getGameMode();
        sf::Event event;
    	
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        	
           game->processEvent(event);
        }

        window.clear();
    	
        game->draw(&window);
    	
        window.display();
    }

    return 0;
}
