#include "interactionexplore.hpp"
#include "confv.hpp"
void gautier::interactionexplore::buildrenderstate(const sf::Vector2u& newsize) {
	_parentsize = newsize;/*May need some validation logic to check if the size actually changed.*/

	sizebackgroundlayout();

	_parentprevioussize = sf::Vector2u(newsize);

	return;
}
void gautier::interactionexplore::sizebackgroundlayout() {
	if(_parentsize != _parentprevioussize) {
		sf::Vector2f calculatedsize = calculateequidistantpadding(_parentsize);

		setSize(calculatedsize);

		sf::Vector2f calculatedposition = calculateposition(_parentsize);

		setPosition(calculatedposition);

		setFillColor(confv::centralwindowdefaultcolor);
	}

	return;
}
sf::Vector2f gautier::interactionexplore::calculateposition(const sf::Vector2u& parentsize) {
	sf::Vector2f presentsize = getSize();

	const float calculatedx = (parentsize.x - presentsize.x) / 2.0;
	const float calculatedy = (parentsize.y - presentsize.y) / 2.0;

	const sf::Vector2f calculatedposition = sf::Vector2f(calculatedx,calculatedy);

	return calculatedposition;
}
sf::Vector2f gautier::interactionexplore::calculateequidistantpadding(const sf::Vector2u& parentsize) {
	const float calculatedw = (parentsize.x-confv::centralframepaddingx);
	const float calculatedh = (parentsize.y-confv::centralframepaddingy);

	const sf::Vector2f calculatedsize = sf::Vector2f(calculatedw, calculatedh);

	return calculatedsize;
}
