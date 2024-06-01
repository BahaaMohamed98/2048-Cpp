#ifndef INC_2048GAME_GAME_CPP
#define INC_2048GAME_GAME_CPP

#include "headers/Game.h"
#include "headers/helpers.h"

Game::Game() : charWidth(4), grid(4, vector<int>(4, 0)), WIN(false) {
	for (int i = 0; i < 2; ++i)
		addBlock(0);
	titleWidth = ((int) grid.size() * charWidth) + (charWidth << 1) + 1;
}

void Game::logic() {
	while (!checkGameOver()) {
		switch (getInput()) {
			case Keycode::UP:
				if (MoveHandler::moveUp(grid)) {
					addBlock();
					printBoard();
				}
				break;
			case Keycode::RIGHT:
				if (MoveHandler::moveRight(grid)) {
					addBlock();
					printBoard();
				}
				break;
			case Keycode::LEFT:
				if (MoveHandler::moveLeft(grid)) {
					addBlock();
					printBoard();
				}
				break;
			case Keycode::DOWN:
				if (MoveHandler::moveDown(grid)) {
					addBlock();
					printBoard();
				}
				break;
			case Keycode::ESC:
				exit(0);
			default:
				cout << "Invalid\n";
		}
	}
	cout << setw(titleWidth) << (WIN ? "\nYou Win!\n" : "\nGame Over!\n");
}

void Game::printBoard() const {
	clearScreen();

	cout << setw(titleWidth) << "2048 Game\n\n";

	printSeparator();
	for (auto &array: grid) {
		for (auto &value: array) {
			cout << setw(charWidth) << '|';
			if (value != 0)
				cout << color(value) << setw(charWidth) << value << normal;
			else
				cout << setw(charWidth) << ' ';
		}
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

bool Game::checkGameOver() { // Fixme
	for (auto &array: grid)
		for (auto &value: array) {
			if (value == 0)
				return false;
			else if (value == 2048) {
				WIN = true;
				return false;
			}
		}
	return true;
}

void Game::start() {
	printBoard();
	logic();
}

#endif //INC_2048GAME_GAME_CPP

