#pragma once

namespace sf {
	class Time;
	class Event;
	class RenderTarget;
}

/**
 * \brief Used for distinguishing the game and main menu. Can be changed in Game class
 */
class GameMode
{
public:
	virtual ~GameMode() = default;
	virtual void takeCareOfEvent(const sf::Event& event) = 0;
	virtual void draw(sf::RenderTarget* renderTarget) = 0;
	virtual void update(const sf::Time& time) = 0;
};
