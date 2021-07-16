#include "Tetris.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include "Game.h"
#include "TetrominoHeaders.h"

Tetris::Tetris()
{
	playfield.reserve(playfieldSize.y);
	for (sf::Uint32 rowCount = 0; rowCount < playfieldSize.y; ++rowCount)
	{
		std::vector<PlayfieldCell> newRow;
		playfield.push_back(newRow);
		playfield[rowCount].reserve(playfieldSize.x);
		for (sf::Uint32 columnCount = 0; columnCount < playfieldSize.x; ++columnCount)
		{
			sf::RectangleShape* cellImage = new sf::RectangleShape{ sf::Vector2f(squareSize, squareSize) };
			cellImage->setPosition(sf::Vector2f(squareSize * columnCount, squareSize * rowCount));
			
			playfield[rowCount].push_back({EMPTY, cellImage});
		}
	}

	spawnTetromino(new Z());
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

sf::Color Tetris::getColorFromSymbol(sf::Int32 symbol)
{
	switch (symbol)
	{
	case 'j':
		return sf::Color::Blue;
	case 'i':
		return sf::Color::Cyan;
	case 'l':
		return sf::Color(255, 165, 0); // Orange
	case 'o':
		return sf::Color::Yellow;
	case 's':
		return sf::Color::Green;
	case 't':
		return sf::Color(127, 0, 255); // Purple
	case 'z':
		return sf::Color::Red;
	default:
		return sf::Color::Black;
	}
}

void Tetris::draw(sf::RenderTarget* renderTarget)
{
	for (sf::Uint32 rowCount = 0; rowCount < playfield.size(); ++rowCount)
	{
		for (sf::Uint32 columnCount = 0; columnCount < playfield[rowCount].size(); ++columnCount)
		{
			auto cellImage = playfield[rowCount][columnCount].image;
			auto symbol = playfield[rowCount][columnCount].symbol;

			cellImage->setFillColor(getColorFromSymbol(symbol));
			
			renderTarget->draw(*cellImage);
		}
	}
}

void Tetris::processEvent(const sf::Event& event)
{
	
}

void Tetris::update(const sf::Time& elapsedTime)
{
	timeCounter += elapsedTime.asMicroseconds();
	if (timeCounter > maxTime)
	{
		timeCounter = 0;
		if (isColliding(fallingTetromino, sf::Vector2i{ 0, 1 }))
		{
			spawnTetromino(new S());
		}
		else
		{
			eraseTetromino(fallingTetromino);
			fallingTetromino->fall();
			drawTetromino(fallingTetromino);
		}
	}
}

void Tetris::spawnTetromino(Tetromino* tetromino)
{
	fallingTetromino = tetromino;

	fallingTetromino->addPosition(startingPosition);
	drawTetromino(fallingTetromino);

}

void Tetris::setCell(sf::Int32 x, sf::Int32 y, sf::Int32 symbol)
{
	playfield[y][x].symbol = symbol;
}

sf::Int32 Tetris::getCell(sf::Int32 x, sf::Int32 y)const
{
	return playfield[y][x].symbol;
}

void Tetris::drawTetromino(Tetromino* tetromino)
{
	for (const auto& position : tetromino->getPosition())
	{
		setCell(position.x, position.y, tetromino->getSymbol());
	}
}

void Tetris::eraseTetromino(Tetromino* tetromino)
{
	for (const auto& position : tetromino->getPosition())
	{
		setCell(position.x, position.y, EMPTY);
	}
}

bool Tetris::isPointInPlayfieldBorders(const sf::Vector2i& point)
{
	return point.x < playfieldSize.x && point.y < playfieldSize.y
		&& point.x > 0 && point.y > 0;
}

bool Tetris::isColliding(Tetromino* tetromino, sf::Vector2i direction)
{
	// to not check for own position
	eraseTetromino(tetromino);
	
	for (auto& point : tetromino->getPosition())
	{
		auto pointToCheck= point + direction;
		if (isPointInPlayfieldBorders(pointToCheck))
		{
			auto cellToCheck = getCell(pointToCheck.x, pointToCheck.y);
			if (cellToCheck != EMPTY)
			{
				drawTetromino(tetromino);
				return true;
			}			
		}
		else
		{
			drawTetromino(tetromino);
			return true;
		}
	}
	drawTetromino(tetromino);
	return false;
}
