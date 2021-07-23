#pragma once

namespace sf {
	class Time;
	class Event;
	class RenderTarget;
}

/**
 * \brief Can represent the main gameplay, main menu, screen with score etc. Can be changed in Game class
 */
class GameMode
{
public:
	virtual ~GameMode() = default;
	virtual void processEvent(const sf::Event& event) = 0;
	virtual void draw(sf::RenderTarget* renderTarget) = 0;
	virtual void update(const sf::Time& time) = 0;
};
