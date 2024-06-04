#ifndef INC_2048GAME_GAME_H
#define INC_2048GAME_GAME_H

#include <random>
#include <thread>
#include "helpers.h"
#include "MoveHandler.h"
#include "GameTime.h"

using namespace std;

class Game {
private:
	vector<vector<int>> grid;
	int charWidth;
	int titleWidth;
	bool WIN;
	int score;
	int moveCounter;
	GameTime time;
public:
	Game();

	void initialize();

	void logic();

	void printBoard(bool printMenu = true);

	void printSeparator() const;

	void addBlock(int max = 1);

	bool checkGameOver();

	void start();
};

#endif //INC_2048GAME_GAME_H
