#include "Tetris.h"

#include <functional>
#include <iostream>
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
			auto* cellImage = new sf::RectangleShape{ sf::Vector2f(squareSize, squareSize) };
			cellImage->setPosition(sf::Vector2f(squareSize * columnCount, squareSize * rowCount));
			
			playfield[rowCount].push_back({EMPTY, cellImage});
		}
	}

	spawnTetromino(tetroQueue.getNext());
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

void Tetris::moveFallingTetromino(const sf::Vector2i direction)
{
	if (!isColliding(fallingTetromino, direction))
	{
		eraseTetromino(fallingTetromino);
		fallingTetromino->addPosition(direction);
		drawTetromino(fallingTetromino);
	}
}

void Tetris::rotateFallingTetromino(bool isClockwise)
{
	if (!isColliding(fallingTetromino, isClockwise))
	{
		eraseTetromino(fallingTetromino);
		fallingTetromino->rotate(isClockwise);
		drawTetromino(fallingTetromino);
	}	
}

void Tetris::speedUp()
{
	maxTime = fastSpeedTime;
}

void Tetris::slowDown()
{
	maxTime = normalSpeedTime;
}

void Tetris::removeRowAtIndex(sf::Int32 index)
{
	for (sf::Int32 columnCount = 0; columnCount < playfieldSize.x; ++columnCount)
	{
		setCell(columnCount, index, EMPTY);
	}
}

void Tetris::dropDownAllRowsBefore(sf::Int32 rowIndex)
{
	for (sf::Int32 rowCount = rowIndex; rowCount > 0; --rowCount)
	{
		for (sf::Int32 columnCount = 0; columnCount < playfieldSize.x; ++columnCount)
		{
			setCell(columnCount, rowCount, getCell(columnCount, rowCount - 1));
		}
	}
}

void Tetris::clearFilledLines()
{
	for (sf::Int32 rowCount = 0; rowCount < playfieldSize.y; ++rowCount)
	{
		bool isFilled = true;
		for (sf::Int32 columnCount = 0; columnCount < playfieldSize.x; ++columnCount)
		{			
			const sf::Int32 cell = getCell(columnCount, rowCount);
			if (cell == EMPTY)
			{
				isFilled = false;
			}
		}
		if (isFilled)
		{
			removeRowAtIndex(rowCount);
			dropDownAllRowsBefore(rowCount);
		}
	}
}

void Tetris::processInput(const sf::Event::KeyEvent& key)
{
	const auto left = sf::Vector2i(-1, 0);
	const auto right = sf::Vector2i(1, 0);
	
	switch (key.code)
	{
	case sf::Keyboard::A:
		moveFallingTetromino(left);
		break;
	case sf::Keyboard::D:
		moveFallingTetromino(right);
		break;
	case sf::Keyboard::R:
		rotateFallingTetromino(true);
		break;
	case sf::Keyboard::E:
		rotateFallingTetromino(false);
		break;
	case sf::Keyboard::S:
		speedUp();
		break;
	default:
		break;
	}
}

void Tetris::processEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		processInput(event.key);
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::S)
		{
			slowDown();
		}
	}
}

void Tetris::nextTetromino()
{
	clearFilledLines();
	delete fallingTetromino;
	spawnTetromino(tetroQueue.getNext());
}

void Tetris::update(const sf::Time& elapsedTime)
{
	const auto down = sf::Vector2i{ 0, 1 };
	
	timeCounter += elapsedTime.asMicroseconds();
	if (timeCounter > maxTime)
	{
		timeCounter = 0;
		if (isColliding(fallingTetromino, down))
		{
			nextTetromino();
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
		&& point.x >= 0 && point.y >= 0;
}

bool Tetris::isColliding(Tetromino* tetromino, sf::Vector2i direction)
{
	// to not check for own position
	eraseTetromino(tetromino);
	
	for (auto& point : tetromino->getPosition())
	{
		const sf::Vector2i pointToCheck = point + direction;
		if (isPointInPlayfieldBorders(pointToCheck))
		{
			const sf::Int32 cellToCheck = getCell(pointToCheck.x, pointToCheck.y);
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

bool Tetris::isColliding(Tetromino* tetromino, bool isClockwise)
{
	eraseTetromino(tetromino);
	tetromino->rotate(isClockwise);

	for (auto point : tetromino->getPosition())
	{
		if (isPointInPlayfieldBorders(point))
		{
			const sf::Int32 cellToCheck = getCell(point.x, point.y);
			if (cellToCheck != EMPTY)
			{
				tetromino->rotate(!isClockwise);
				drawTetromino(tetromino);
				return true;
			}
		}
		else
		{
			tetromino->rotate(!isClockwise);
			drawTetromino(tetromino);
			return true;
		}
	}
	tetromino->rotate(!isClockwise);
	drawTetromino(tetromino);
	return false;
}
