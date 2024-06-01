//#include "../headers/helpers.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

std::string color(int value) {
	const std::vector<std::string> colors = {
			"\033[0m",     // Reset
			"\033[1;33m", //yellow
			"\033[1;32m", "\033[0;32m", // green
			"\033[1;31m", "\033[0;31m", //red
			"\033[1;35m", "\033[0;35m", // magenta
			"\033[0;34m", "\033[1;34m", // blue
			"\033[0;36m", "\033[1;36m", // cyan
	};
	if (value == 0)
		return colors.front();
	return colors[(int) log2(value)];
}

int main() {
	cout<<setw(15)<<'x'<<'y';
	getchar();
}