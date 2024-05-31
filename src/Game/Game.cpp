#ifndef INC_2048GAME_GAME_CPP
#define INC_2048GAME_GAME_CPP

#include "Game.h"

Game::Game(int dimension) : charWidth(5), grid(dimension, vector<int>(dimension, 0)) {
	for (int i = 0; i < 2; ++i)
		addBlock(0);
	titleWidth = ((int) grid.size() * charWidth) + (charWidth << 1) + 1;
}

int Game::getInput() {
	if (int input = (int) getch();(input != 224))
		return input;
	return getch();
}

void Game::logic() {
	while (!checkGameOver()) {
		switch (getInput()) {
			case UP:
				if (MoveHandler::moveUp(grid)) {
					addBlock();
					display();
				}
				break;
			case RIGHT:
				if (MoveHandler::moveRight(grid)) {
					addBlock();
					display();
				}
				break;
			case LEFT:
				if (MoveHandler::moveLeft(grid)) {
					addBlock();
					display();
				}
				break;
			case DOWN:
				if (MoveHandler::moveDown(grid)) {
					addBlock();
					display();
				}
				break;
			case ESC:
				exit(0);
			default:
				cout << "Invalid\n";
		}
	}
	cout << setw(titleWidth) << "\nGame Over!\n";
}

void Game::display() const {
	system("cls");

	cout << setw(titleWidth) << "2048 Game\n\n";

	printSeparator();
	for (auto &array: grid) {
		for (auto &value: array)
			cout << setw(charWidth) << '|' << setw(charWidth) << value;
		cout << setw(charWidth) << '|' << "\n";
		printSeparator();
	}
	cout << "\n\n[esc] Exit\n\n";
}

void Game::printSeparator() const {
	for (int i = 0; i < charWidth - 1; ++i)
		cout << ' ';
	for (int i = 0; i < (int) grid.size(); i++)
		for (int j = 0; j < (charWidth << 1); ++j)
			if (j % ((titleWidth)) == 0)
				cout << '+';
			else
				cout << '-';
	cout << "+\n";
}

void Game::addBlock(int max) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, max);
	std::uniform_int_distribution<std::mt19937::result_type> dist7(0, (int) grid.size() - 1);

	int rowIndex = 0, columnIndex = 0;
	while (grid[rowIndex][columnIndex] != 0)
		rowIndex = (int) dist7(rng), columnIndex = (int) dist7(rng);
	grid[rowIndex][columnIndex] = 2 << dist6(rng);
}

bool Game::checkGameOver() {
	for (auto &array: grid)
		for (auto &value: array) {
			if (value == 0)
				return false;
		}
	return true;
}

void Game::start() {
	display();
	logic();
}

#endif //INC_2048GAME_GAME_CPP

