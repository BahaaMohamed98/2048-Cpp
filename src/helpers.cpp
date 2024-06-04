#ifndef INC_2048GAME_HELPERS_CPP
#define INC_2048GAME_HELPERS_CPP

#include "headers/helpers.h"

#ifdef _WIN32

#include <conio.h>

int getCharInput() {
	return (int) getch();
}

#else
#include <termios.h>
#include <unistd.h>
#include <cstdio>

int getCharInput() {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr(STDIN_FILENO, &oldattr);       // Get current terminal attributes
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);     // Disable canonical mode and echoing
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr); // Apply new attributes immediately
	ch = getchar();                          // Read a single character
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); // Restore original attributes
	return ch;
}
#endif

void clearScreen() {
#ifdef _WIN32 // For Windows
	system("cls");
#else // for linux and macOS
	system("clear");
#endif
}

int getKeyboardInput() {
	if (int input = getCharInput();(input != 224))
		return input;
	return getCharInput();
}

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

#endif //INC_2048GAME_HELPERS_CPP