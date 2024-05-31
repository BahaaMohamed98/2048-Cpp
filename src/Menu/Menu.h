#ifndef INC_2048GAME_MENU_H
#define INC_2048GAME_MENU_H

#include "../Game/Game.h"

class Menu {
private:
	Game game;
public:
	Menu();

	void display();

	void displayInstructions();

	void getInput();

//	void settings();

	void miniMenu();
};

#endif //INC_2048GAME_MENU_H
