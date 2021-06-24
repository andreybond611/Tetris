#pragma once

namespace sf {
	class Event;
	class RenderTarget;
}

class GameMode
{
public:
	virtual ~GameMode() = default;
	virtual void processEvent(sf::Event& event) = 0;
	virtual void draw(sf::RenderTarget* renderTarget) = 0;	
};
