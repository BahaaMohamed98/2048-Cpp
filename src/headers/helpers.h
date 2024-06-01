#ifndef INC_2048GAME_HELPERS_H
#define INC_2048GAME_HELPERS_H

#include <iostream>
#include <vector>
#include <cmath>

#define cur_off "\033[?25l"
#define normal "\033[0m"

enum Keycode {
	ESC = 27,
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

void clearScreen();

int getCharInput();

int getInput();

std::string color(int value) ;

#endif //INC_2048GAME_HELPERS_H
