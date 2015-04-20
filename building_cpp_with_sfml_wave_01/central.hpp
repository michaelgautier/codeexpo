#ifndef central_hpp
#define central_hpp
#include <SFML/Graphics.hpp>
#include "confv.hpp"
#include "interactionexplore.hpp"
class central {
public:
	central();
	int execute();
	~central();
private:
	float _width;
	float _height;
	bool _resized;
	bool _allowconsoleoutput;

	uint _desktopwidth;
	uint _desktopheight;
	uint _desktopbitsperpixel;

	sf::RenderWindow* centralwindow;
	interactionexplore currentframe;
	const sf::VideoMode createdefaultvideomode();
	void showconsoleoutput();
	void buildeventstate();
	void processeventstate();
	void buildrenderstate();
	void processrenderstate();
};
#endif
