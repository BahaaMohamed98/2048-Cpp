#ifndef INC_2048GAME_GAME_CPP
#define INC_2048GAME_GAME_CPP

#include "Game.h"

Game::Game(int dimension) : charWidth(5), grid(dimension, vector<int>(dimension, 0)), gridSize(dimension) {
	for (int i = 0; i < 2; ++i)
		addBlock(0);
	titleWidth = (gridSize * charWidth) + (charWidth << 1) + 1;
}

void Game::logic() {
	while (!checkGameOver()) {
		checkGameOver();
		if ((int) getch() != 224)
			cout << "Invalid\n";
		else
			switch ((int) getch()) {
				case UP:
					if (up()) {
						addBlock();
						display();
					}
					break;
				case RIGHT:
					if (right()) {
						addBlock();
						display();
					}
					break;
				case LEFT:
					if (left()) {
						addBlock();
						display();
					}
					break;
				case DOWN:
					if (down()) {
						addBlock();
						display();
					}
					break;
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
	for (auto &x: grid) {
		for (auto &y: x)
			cout << setw(charWidth) << '|' << setw(charWidth) << y;
		cout << setw(charWidth) << '|' << "\n";
		printSeparator();
	}
}

void Game::printSeparator() const {
	for (int i = 0; i < charWidth - 1; ++i)
		cout << ' ';
	for (int i = 0; i < gridSize; i++)
		for (int j = 0; j < (charWidth << 1); ++j)
			cout << '-';
	cout << "-\n";
}

bool Game::up() {
	bool first = false, second = false;
	for (int i = 0; i < gridSize; ++i) {//cols
		for (int j = 1; j < gridSize; ++j) {//rows
			int temp = j;
			while (temp > 0 and grid[temp - 1][i] == 0 and grid[temp][i] != 0)
				swap(grid[temp][i], grid[temp - 1][i]), temp--, first = true;
		}
	}
	for (int i = 0; i < gridSize - 1; ++i)
		for (int j = 0; j < gridSize; ++j)
			if (grid[i][j] == 0)
				swap(grid[i][j], grid[i + 1][j]);
			else if (grid[i][j] == grid[i + 1][j])
				grid[i][j] <<= 1, grid[i + 1][j] = 0, second = true;
	return first | second;
}

bool Game::down() {
	bool first = false, second = false;
	for (int i = gridSize - 1; i >= 0; --i) {//cols
		for (int j = gridSize - 2; j >= 0; --j) {//rows
			int temp = j;
			while (temp < gridSize - 1 and grid[temp + 1][i] == 0 and grid[temp][i] != 0)
				swap(grid[temp][i], grid[temp + 1][i]), temp++, first = true;
		}
	}
	for (int i = gridSize - 2; i >= 0; --i)
		for (int j = gridSize - 1; j >= 0; --j)
			if (grid[i + 1][j] == 0)
				swap(grid[i][j], grid[i + 1][j]);
			else if (grid[i + 1][j] == grid[i][j])
				grid[i + 1][j] <<= 1, grid[i][j] = 0, second = true;
	return first | second;
}

bool Game::right() {
	bool first = false, second = false;
	for (int i = gridSize - 1; i >= 0; --i) {
		for (int j = gridSize - 2; j >= 0; --j) {
			int temp = j;
			while ((temp < gridSize - 1) and grid[i][temp + 1] == 0 and grid[i][temp] != 0)
				swap(grid[i][temp + 1], grid[i][temp]), temp++, first = true;
		}
	}
	for (int i = gridSize - 1; i >= 0; --i) {
		for (int j = gridSize - 1; j > 0; --j) {
			if (grid[i][j] == 0)
				swap(grid[i][j], grid[i][j - 1]);
			else if (grid[i][j] == grid[i][j - 1])
				grid[i][j] <<= 1, grid[i][j - 1] = 0, second = true;
		}
	}
	return first | second;
}

bool Game::left() {
	bool first = false, second = false;
	for (auto &gridRow: grid) {
		for (int j = 1; j < gridSize; ++j) {
			int temp = j;
			while (temp > 0 and gridRow[temp - 1] == 0 and gridRow[temp] != 0)
				swap(gridRow[temp - 1], gridRow[temp]), temp--, first = true;
		}
	}
	for (auto &gridRow: grid) {
		for (int j = 1; j < gridSize; ++j) {
			if (gridRow[j - 1] == 0)
				swap(gridRow[j], gridRow[j - 1]);
			else if (gridRow[j] == gridRow[j - 1])
				gridRow[j - 1] <<= 1, gridRow[j] = 0, second = true;
		}
	}
	return first | second;
}

void Game::addBlock(int max) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, max);
	std::uniform_int_distribution<std::mt19937::result_type> dist7(0, gridSize - 1);

	int x = 0, y = 0;
	while (grid[x][y] != 0)
		x = (int) dist7(rng), y = (int) dist7(rng);
	grid[x][y] = 2 << dist6(rng);
}

bool Game::checkGameOver() {
	for (auto &x: grid)
		for (auto &y: x) {
			if (y == 0)
				return false;
		}
	return true;
}

void Game::run() {
	display();
	logic();
}


#endif //INC_2048GAME_GAME_CPP

