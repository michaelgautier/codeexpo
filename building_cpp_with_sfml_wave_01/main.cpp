#include "central.hpp"
using namespace gautier;
int main() {
	central centralInstance = central();
	int exitcode = centralInstance.execute();

	return exitcode;
}
