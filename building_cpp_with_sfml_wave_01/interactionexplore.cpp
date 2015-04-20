#include "interactionexplore.hpp"
#include "confv.hpp"
void interactionexplore::parentframechangedsize(const sf::Vector2u& newsize) {
	sf::Vector2f calculatedsize = calculateequidistantpadding(newsize);

	setSize(calculatedsize);

	sf::Vector2f calculatedposition = sf::Vector2f(0,0);//calculateposition(newsize);

	setPosition(calculatedposition);

	update();

	return;
}
sf::Vector2f interactionexplore::calculateposition(const sf::Vector2u& parentsize) {
	sf::Vector2f presentsize = getSize();

	const float calculatedx = (parentsize.x - presentsize.x) / 2.0;
	const float calculatedy = (parentsize.y - presentsize.y) / 2.0;

	const sf::Vector2f calculatedposition = sf::Vector2f(calculatedx,calculatedy);

	return calculatedposition;
}
sf::Vector2f interactionexplore::calculateequidistantpadding(const sf::Vector2u& parentsize) {
	const float calculatedw = (parentsize.x-confv::centralframepaddingx());
	const float calculatedh = (parentsize.y-confv::centralframepaddingy());

	const sf::Vector2f calculatedsize = sf::Vector2f(calculatedw, calculatedh);

	return calculatedsize;
}
