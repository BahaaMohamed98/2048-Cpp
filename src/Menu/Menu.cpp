#ifndef INC_2048GAME_MENU_CPP
#define INC_2048GAME_MENU_CPP

#include "Menu.h"

Menu::Menu() : gg(4) {}

void Menu::display() {
	cout << "\033[?25l";
	system("cls");
	cout << "[1] Start game\n[2] Instructions\n[3] Settings\n[4] Exit\n";
	getInput();
}

void Menu::getInput() {
	switch (getch()) {
		case '1':
			gg.run();
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
	cout << "play";
	miniMenu();
}


#endif //#ifndef INC_2048GAME_MENU_CPP




