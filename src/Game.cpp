#ifndef INC_2048GAME_GAME_CPP
#define INC_2048GAME_GAME_CPP

#include "headers/Game.h"
#include "headers/helpers.h"

Game::Game() : charWidth(5), grid(4, vector<int>(4, 0)), WIN(false),
               titleWidth((int) grid.size() * charWidth + (charWidth << 1) + 1), score(0), moveCounter(0) {
	initialize();
}

void Game::initialize() {
	grid = vector<vector<int>>(4, vector<int>(4, 0));
	WIN = false;
	score = 0;
	moveCounter = 0;
	for (int i = 0; i < 2; ++i)
		addBlock(0);
}

void Game::logic() {
	while (!checkGameOver()) {
		switch (getInput()) {
			case Keycode::UP:
				if (MoveHandler::moveUp(grid, score)) {
					addBlock();
					printBoard();
					moveCounter++;
				}
				break;
			case Keycode::RIGHT:
				if (MoveHandler::moveRight(grid, score)) {
					addBlock();
					printBoard();
					moveCounter++;
				}
				break;
			case Keycode::LEFT:
				if (MoveHandler::moveLeft(grid, score)) {
					addBlock();
					printBoard();
					moveCounter++;
				}
				break;
			case Keycode::DOWN:
				if (MoveHandler::moveDown(grid, score)) {
					addBlock();
					printBoard();
					moveCounter++;
				}
				break;
			case Keycode::ESC:
				exit(0);
			default:
				cout << "Invalid\n";
		}
	}
	clearScreen();
	printBoard(false);
	cout << "\n\n";
	cout << setw(titleWidth) << (WIN ? "You Win!\n" : "Game Over!\n");
}

void Game::printBoard(bool printMenu) const {
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
	cout << "\n" << setw((charWidth << 1) - 1) << ' ' << "Score: " << score
	     << setw(charWidth << 2) << "moves: " << moveCounter;
	if (printMenu)
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
	for (int i = 0; i < (int) grid.size(); ++i) {
		for (int j = 0; j < (int) grid.size(); ++j) {
			if (grid[i][j] == 0 or
			    (i < (int) grid.size() - 1 and grid[i][j] == grid[i + 1][j]) or
			    (j < (int) grid.size() - 1 and grid[i][j] == grid[i][j + 1]))
				return false;
			if (grid[i][j] == 2048) {
				WIN = true;
				return true;
			}
		}
	}
	return true;
}

void Game::start() {
	initialize();
	printBoard();
	logic();
}

#endif //INC_2048GAME_GAME_CPP

