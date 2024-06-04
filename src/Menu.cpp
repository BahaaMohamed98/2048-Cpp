#ifndef INC_2048GAME_MENU_CPP
#define INC_2048GAME_MENU_CPP

#include "Menu.h"
#include "helpers.h"

void Menu::printMenu() {
	cout << cur_off;
	clearScreen();
	cout << "[1] Start game\n[2] Instructions\n[Esc] Exit\n";
	getInput();
}

void Menu::getInput() {
	switch ((char) getCharInput()) {
		case '1':
			game.start();
			miniMenu();
			break;
		case '2':
			PrintInstructions();
			break;
		case Keycode::ESC:
			exit(0);
		default:
			cout << "Invalid choice\n";
			getInput();
	}
}

void Menu::miniMenu() {
	bool firstInvalid = true;
	cout << "\n\n[1] Main Menu\n[Esc] Exit\n";
	do {
		switch (getCharInput()) {
			case '1':
				printMenu();
				return;
			case Keycode::ESC:
				exit(0);
			default:
				if (firstInvalid)
					cout << "\nInvalid\n";
				firstInvalid = false;
		}
	} while (true);
}

void Menu::PrintInstructions() {
	clearScreen();
	cout << "\t\tWelcome to the 2048 Game!\n\n"
	     << "Instructions:\n\n"
	     << "1. Use the arrow keys to move the tiles.\n"
	     << "2. Tiles with the same number merge into one when they touch.\n"
	     << "3. Your goal is to create a tile with the number 2048.\n"
	     << "4. The game ends when there are no more possible moves.\n";
	miniMenu();
}

#endif //#ifndef INC_2048GAME_MENU_CPP




