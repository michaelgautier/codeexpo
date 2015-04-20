#ifndef interactionexplore_hpp
#define interactionexplore_hpp
#include <SFML/Graphics/RectangleShape.hpp>
class interactionexplore : public sf::RectangleShape {
public:
	interactionexplore (const sf::Vector2f &size=sf::Vector2f(0, 0)):RectangleShape(size) {};
	void parentframechangedsize(const sf::Vector2u& newsize);
private:

	sf::Vector2f calculateposition(const sf::Vector2u& parentsize);
	sf::Vector2f calculateequidistantpadding(const sf::Vector2u& parentsize);
};
#endif
