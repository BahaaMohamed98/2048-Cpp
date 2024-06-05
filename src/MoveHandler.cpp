#ifndef INC_2048GAME_MOVEHANDLER_CPP
#define INC_2048GAME_MOVEHANDLER_CPP

#include "MoveHandler.h"

bool MoveHandler::moveUp(Game &game) {

	int gridSize = (int) game.grid.size();
	bool moved = false;
	for (int i = 0; i < gridSize; ++i) //cols
		for (int j = 1; j < gridSize; ++j) //rows
			for (int temp = j; temp > 0 and game.grid[temp - 1][i] == 0 and game.grid[temp][i] != 0; temp--)
				swap(game.grid[temp][i], game.grid[temp - 1][i]), moved = true;

	for (int i = 0; i < gridSize - 1; ++i) {
		for (int j = 0; j < gridSize; ++j) {
			if (game.grid[i][j] == 0)
				swap(game.grid[i][j], game.grid[i + 1][j]);
			else if (game.grid[i][j] == game.grid[i + 1][j]) {
				game.grid[i][j] <<= 1, game.grid[i + 1][j] = 0;
				moved = true;
				game.score += game.grid[i][j];
			}
		}
	}
	return moved;
}

bool MoveHandler::moveDown(Game &game) {
	int gridSize = (int) game.grid.size();
	bool moved = false;
	for (int i = gridSize - 1; i >= 0; --i) //cols
		for (int j = gridSize - 2; j >= 0; --j) //rows
			for (int temp = j; temp < gridSize - 1 and game.grid[temp + 1][i] == 0 and game.grid[temp][i] != 0; temp++)
				swap(game.grid[temp][i], game.grid[temp + 1][i]), moved = true;

	for (int i = gridSize - 2; i >= 0; --i) {
		for (int j = gridSize - 1; j >= 0; --j) {
			if (game.grid[i + 1][j] == 0)
				swap(game.grid[i][j], game.grid[i + 1][j]);
			else if (game.grid[i + 1][j] == game.grid[i][j]) {
				game.grid[i + 1][j] <<= 1, game.grid[i][j] = 0;
				moved = true;
				game.score += game.grid[i + 1][j];
			}
		}
	}
	return moved;
}

bool MoveHandler::moveRight(Game &game) {
	int gridSize = (int) game.grid.size();
	bool moved = false;
	for (int i = gridSize - 1; i >= 0; --i)
		for (int j = gridSize - 2; j >= 0; --j)
			for (int temp = j;
			     (temp < gridSize - 1) and game.grid[i][temp + 1] == 0 and game.grid[i][temp] != 0; temp++)
				swap(game.grid[i][temp + 1], game.grid[i][temp]), moved = true;

	for (int i = gridSize - 1; i >= 0; --i) {
		for (int j = gridSize - 1; j > 0; --j) {
			if (game.grid[i][j] == 0)
				swap(game.grid[i][j], game.grid[i][j - 1]);
			else if (game.grid[i][j] == game.grid[i][j - 1]) {
				game.grid[i][j] <<= 1, game.grid[i][j - 1] = 0;
				moved = true;
				game.score += game.grid[i][j];
			}
		}
	}
	return moved;
}

bool MoveHandler::moveLeft(Game &game) {
	int gridSize = (int) game.grid.size();
	bool moved = false;
	for (auto &gridRow: game.grid)
		for (int j = 1; j < gridSize; ++j)
			for (int temp = j; temp > 0 and gridRow[temp - 1] == 0 and gridRow[temp] != 0; temp--)
				swap(gridRow[temp - 1], gridRow[temp]), moved = true;

	for (auto &gridRow: game.grid) {
		for (int j = 1; j < gridSize; ++j) {
			if (gridRow[j - 1] == 0)
				swap(gridRow[j], gridRow[j - 1]);
			else if (gridRow[j] == gridRow[j - 1]) {
				gridRow[j - 1] <<= 1, gridRow[j] = 0;
				moved = true;
				game.score += gridRow[j - 1];
			}
		}
	}
	return moved;
}

bool MoveHandler::move(Game &game, int keycode) {
	switch (keycode) {
		case Keycode::UP:
			return moveUp(game);
		case Keycode::DOWN:
			return moveDown(game);
		case Keycode::RIGHT:
			return moveRight(game);
		case Keycode::LEFT:
			return moveLeft(game);
		default:
			throw std::exception();
	}
}

#endif  //INC_2048GAME_MOVEHANDLER_CPP
