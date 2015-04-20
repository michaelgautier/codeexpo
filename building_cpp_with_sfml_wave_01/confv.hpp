#ifndef confv_hpp
#define confv_hpp
#include <string>
#include <SFML/Graphics.hpp>
class confv {
private:
	static const int _centralframepaddingx = 0;
	static const int _centralframepaddingy = 0;

public:

	static const std::string centralwindowname() {
		return std::string("Gautier's Window");
	}
	static const int centralframepaddingx() {
		return _centralframepaddingx;
	}
	static const int centralframepaddingy() {
		return _centralframepaddingy;
	}
};
#endif
