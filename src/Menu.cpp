#ifndef INC_2048GAME_MENU_CPP
#define INC_2048GAME_MENU_CPP

#include "headers/Menu.h"
#include "headers/helpers.h"

void Menu::printMenu() {
	cout << cur_off;
	clearScreen();
	cout << "[1] Start game\n[2] Instructions\n[3] Exit\n";
	getInput();
}

void Menu::getInput() {
	switch ((char) getCharInput()) {
		case '1':
			game.start();
			printMiniMenu();
			break;
		case '2':
			PrintInstructions();
			break;
		case '3':
			exit(0);
		default:
			cout << "Invalid choice\n";
			getInput();
	}
}

void Menu::printMiniMenu() {
	cout << "\n\n[1] Main Menu\n[2] Exit\n";
	switch (getCharInput()) {
		case '1':
			printMenu();
			break;
		case '2':
			exit(0);
		default:
			cout << "Invalid choice";
			printMiniMenu();
	}
}

void Menu::PrintInstructions() {
	clearScreen();
	cout << "\t\tWelcome to the 2048 Game!\n\n"
	     << "Instructions:\n\n"
	     << "1. Use the arrow keys to move the tiles.\n"
	     << "2. Tiles with the same number merge into one when they touch.\n"
	     << "3. Your goal is to create a tile with the number 2048.\n"
	     << "4. The game ends when there are no more possible moves.\n";
	printMiniMenu();
}

#endif //#ifndef INC_2048GAME_MENU_CPP




