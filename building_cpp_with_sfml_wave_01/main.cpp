#include "central.hpp"
int main() {
	central centralInstance = central();
	int exitcode = centralInstance.execute();

	return exitcode;
}