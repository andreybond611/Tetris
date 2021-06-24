#include "Tetris.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include "Game.h"

Tetris::Tetris()
{
	playfield.reserve(playfieldSize.y);
	for (sf::Uint32 rowCount = 0; rowCount < playfieldSize.y; ++rowCount)
	{
		std::vector<TetrisCell> newRow;
		playfield.push_back(newRow);
		playfield[rowCount].reserve(playfieldSize.x);
		for (sf::Uint32 columnCount = 0; columnCount < playfieldSize.x; ++columnCount)
		{
			sf::RectangleShape* cell = new sf::RectangleShape{ sf::Vector2f(squareSize, squareSize) };
			cell->setPosition(sf::Vector2f(squareSize * columnCount, squareSize * rowCount));
			
			playfield[rowCount].push_back({0, cell});
		}
	}
}

Tetris::~Tetris()
{
	for (int rowCount = 0; rowCount < playfield.size(); ++rowCount)
	{
		for (auto& [symbol, image] : playfield[rowCount])
		{
			delete image;
			image = nullptr;
		}
	}
}

void Tetris::draw(sf::RenderTarget* renderTarget)
{
	for (sf::Uint32 rowCount = 0; rowCount < playfield.size(); ++rowCount)
	{
		for (sf::Uint32 columnCount = 0; columnCount < playfield[rowCount].size(); ++columnCount)
		{
			auto cellImage = playfield[rowCount][columnCount].image;
			
			cellImage->setFillColor(sf::Color::Green);
			
			renderTarget->draw(*cellImage);
		}
	}
}

void Tetris::processEvent(sf::Event& event)
{
	
}
