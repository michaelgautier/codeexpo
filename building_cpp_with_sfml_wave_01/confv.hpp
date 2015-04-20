#ifndef confv_hpp
#define confv_hpp
#include <string>
#include <SFML/Graphics.hpp>
namespace gautier {
class confv {
public:
	confv();
	static const std::string centralwindowname;
	static const int centralframepaddingx = 10;
	static const int centralframepaddingy = 10;
	static const int centralwindowdefaultwidth = 640;
	static const int centralwindowdefaultheight = 480;
	static const sf::Color centralwindowdefaultcolor;
private:
	static const int _colorvalue_r = 0;
	static const int _colorvalue_g = 1;
	static const int _colorvalue_b = 2;
	static const int _colorvalue_al = 3;
	static const int _colorvalue_size = 4;
	static const int _turqouiscolorvalues[_colorvalue_size];
};
}
#endif
