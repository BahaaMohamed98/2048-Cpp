#ifndef INC_2048GAME_GAME_CPP
#define INC_2048GAME_GAME_CPP

#include "Game.h"

Game::Game() : charWidth(4), grid(4, vector<int>(4, 0)), WIN(false),
               titleWidth((int) grid.size() * charWidth + (charWidth << 1) + 1), score(0), moveCounter(0) {}

void Game::initialize() {
	grid = vector<vector<int>>(4, vector<int>(4, 0));
	WIN = false;
	score = 0;
	moveCounter = 0;
	for (int i = 0; i < 2; ++i)
		addTile(0);
}

void Game::logic() {
	bool firstInvalid = true;
	while (true) {

		int input = getKeyboardInput();

		if (input == Keycode::ESC)
			exit(0);

		try {
			bool moved;
			if (moved = MoveHandler::move(*this, input);moved)
				moveCounter++;

			if (checkGameOver())
				break;
			if (!moved)
				continue;

			addTile();
			printBoard();
			firstInvalid = true;
		} catch (const std::exception &exception) {
			if (!firstInvalid)
				continue;
			cout << "Invalid\n";
			firstInvalid = false;
		}
	}
	gameTime.stop();
	printBoard(false);
	cout << "\n\n";
	cout << setw(titleWidth) << (WIN ? "You Win!\n\n" : "Game Over!\n\n");
	gameTime.printTime(charWidth);
}

void Game::printBoard(bool printMenu) {
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
	     << setw((charWidth << 2) - 1) << "moves: " << moveCounter;
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

void Game::addTile(int max) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, max);
	std::uniform_int_distribution<std::mt19937::result_type> dist7(0, (int) grid.size() - 1);

	int rowIndex, columnIndex;
	do {
		rowIndex = (int) dist7(rng), columnIndex = (int) dist7(rng);
	} while (grid[rowIndex][columnIndex] != 0);

	grid[rowIndex][columnIndex] = 2 << dist6(rng);
}

bool Game::checkGameOver() {
	for (const auto &array: grid) {
		for (const auto &value: array) {
			if (value == 2048) {
				WIN = true;
				return true;
			}
		}
	}
	for (int i = 0; i < (int) grid.size(); ++i) {
		for (int j = 0; j < (int) grid.size(); ++j) {
			if (grid[i][j] == 0 or
			    (i < (int) grid.size() - 1 and grid[i][j] == grid[i + 1][j]) or
			    (j < (int) grid.size() - 1 and grid[i][j] == grid[i][j + 1]))
				return false;
		}
	}
	return true;
}

void Game::run() {
	initialize();
	printBoard();
	gameTime.start();
	logic();
}

#endif //INC_2048GAME_GAME_CPP

