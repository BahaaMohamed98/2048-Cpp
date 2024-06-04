#ifndef INC_2048GAME_MOVEHANDLER_CPP
#define INC_2048GAME_MOVEHANDLER_CPP

#include "MoveHandler.h"

bool MoveHandler::moveUp(vector<vector<int>> &grid, int &score) {
	int gridSize = (int) grid.size();
	bool moved = false;
	for (int i = 0; i < gridSize; ++i) {//cols
		for (int j = 1; j < gridSize; ++j) {//rows
			int temp = j;
			while (temp > 0 and grid[temp - 1][i] == 0 and grid[temp][i] != 0)
				swap(grid[temp][i], grid[temp - 1][i]), temp--, moved = true;
		}
	}
	for (int i = 0; i < gridSize - 1; ++i)
		for (int j = 0; j < gridSize; ++j)
			if (grid[i][j] == 0)
				swap(grid[i][j], grid[i + 1][j]);
			else if (grid[i][j] == grid[i + 1][j]) {
				grid[i][j] <<= 1, grid[i + 1][j] = 0;
				moved = true;
				score += grid[i][j];
			}
	return moved;
}

bool MoveHandler::moveDown(vector<vector<int>> &grid, int &score) {
	int gridSize = (int) grid.size();
	bool moved = false;
	for (int i = gridSize - 1; i >= 0; --i) {//cols
		for (int j = gridSize - 2; j >= 0; --j) {//rows
			int temp = j;
			while (temp < gridSize - 1 and grid[temp + 1][i] == 0 and grid[temp][i] != 0)
				swap(grid[temp][i], grid[temp + 1][i]), temp++, moved = true;
		}
	}
	for (int i = gridSize - 2; i >= 0; --i)
		for (int j = gridSize - 1; j >= 0; --j)
			if (grid[i + 1][j] == 0)
				swap(grid[i][j], grid[i + 1][j]);
			else if (grid[i + 1][j] == grid[i][j]) {
				grid[i + 1][j] <<= 1, grid[i][j] = 0;
				moved = true;
				score += grid[i][j];
			}
	return moved;
}

bool MoveHandler::moveRight(vector<vector<int>> &grid, int &score) {
	int gridSize = (int) grid.size();
	bool moved = false;
	for (int i = gridSize - 1; i >= 0; --i) {
		for (int j = gridSize - 2; j >= 0; --j) {
			int temp = j;
			while ((temp < gridSize - 1) and grid[i][temp + 1] == 0 and grid[i][temp] != 0)
				swap(grid[i][temp + 1], grid[i][temp]), temp++, moved = true;
		}
	}
	for (int i = gridSize - 1; i >= 0; --i) {
		for (int j = gridSize - 1; j > 0; --j) {
			if (grid[i][j] == 0)
				swap(grid[i][j], grid[i][j - 1]);
			else if (grid[i][j] == grid[i][j - 1]) {
				grid[i][j] <<= 1, grid[i][j - 1] = 0;
				moved = true;
				score += grid[i][j];
			}
		}
	}
	return moved;
}

bool MoveHandler::moveLeft(vector<vector<int>> &grid, int &score) {
	int gridSize = (int) grid.size();
	bool moved = false;
	for (auto &gridRow: grid) {
		for (int j = 1; j < gridSize; ++j) {
			int temp = j;
			while (temp > 0 and gridRow[temp - 1] == 0 and gridRow[temp] != 0)
				swap(gridRow[temp - 1], gridRow[temp]), temp--, moved = true;
		}
	}
	for (auto &gridRow: grid) {
		for (int j = 1; j < gridSize; ++j) {
			if (gridRow[j - 1] == 0)
				swap(gridRow[j], gridRow[j - 1]);
			else if (gridRow[j] == gridRow[j - 1]) {
				gridRow[j - 1] <<= 1, gridRow[j] = 0;
				moved = true;
				score += gridRow[j];
			}
		}
	}
	return moved;
}

#endif  //INC_2048GAME_MOVEHANDLER_CPP
