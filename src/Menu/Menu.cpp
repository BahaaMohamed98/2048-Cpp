#ifndef INC_2048GAME_MENU_CPP
#define INC_2048GAME_MENU_CPP

#include "Menu.h"

Menu::Menu() : game(4) {}

void Menu::display() {
	cout << "\033[?25l";
	system("cls");
	cout << "[1] Start game\n[2] Instructions\n[3] Settings\n[4] Exit\n";
	getInput();
}

void Menu::getInput() {
	switch ((char) getch()) {
		case '1':
			game.start();
			miniMenu();
			break;
		case '2':
			displayInstructions();
			break;
		case '3':
//			settings();
			break;
		case '4':
			exit(0);
		default:
			cout << "Invalid choice";
			getInput();
	}
}

void Menu::miniMenu() {
	cout << "\n\n[1] Main Menu\n[2] Exit\n";
	switch (getch()) {
		case '1':
			display();
			break;
		case '2':
			exit(0);
		default:
			cout << "Invalid choice";
			miniMenu();
	}
}

void Menu::displayInstructions() {
	system("cls");
	system("cls");
	cout << "\t\tWelcome to the 2048 Game!\n\n"
	     << "Instructions:\n\n"
	     << "1. Use the arrow keys to move the tiles.\n"
	     << "2. Tiles with the same number merge into one when they touch.\n"
	     << "3. Your goal is to create a tile with the number 2048.\n"
	     << "4. The game ends when there are no more possible moves.\n";
	miniMenu();
}


#endif //#ifndef INC_2048GAME_MENU_CPP




