#ifndef INC_2048GAME_MENU_H
#define INC_2048GAME_MENU_H

#include "Game.h"

class Menu {
private:
	Game game;
public:
	void printMenu();

	void PrintInstructions();

	void getInput();

	void printMiniMenu();
};

#endif //INC_2048GAME_MENU_H
