#pragma once
#include <vector>
#include <SFML/Config.hpp>

#include "GameMode.h"

namespace sf {
	class Shape;
}

struct TetrisCell
{
	sf::Int32 symbol;
	sf::Shape* image;
};

class Tetris : public GameMode
{
public:
	Tetris();
	~Tetris() override;
	virtual void draw(sf::RenderTarget* renderTarget) override;
	virtual void processEvent(sf::Event& event) override;
private:
	
	std::vector<std::vector<TetrisCell>> playfield;
};

