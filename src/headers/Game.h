#ifndef INC_2048GAME_GAME_H
#define INC_2048GAME_GAME_H

#include <random>
#include <iomanip>
#include <thread>
#include "../headers/helpers.h"
#include "MoveHandler.h"

using namespace std;

class Game {
private:
	vector<vector<int>> grid;
	int charWidth;
	int titleWidth;
	bool WIN;
public:
	Game();

	void initialize();

	void logic();

	void printBoard(bool printMenu = true) const;

	void printSeparator() const;

	void addBlock(int max = 1);

	bool checkGameOver();

	void start();
};

#endif //INC_2048GAME_GAME_H
