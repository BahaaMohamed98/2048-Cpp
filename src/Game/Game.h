#ifndef INC_2048GAME_GAME_H
#define INC_2048GAME_GAME_H

#include <iostream>
#include <random>
#include <conio.h>
#include <iomanip>
#include <thread>
#include "MoveHandler/MoveHandler.h"

using namespace std;

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ESC 27

class Game {
private:
	vector<vector<int>> grid;
	int charWidth;
	int titleWidth;
public:
	explicit Game(int dimension = 4);

	static int getInput();

	void logic();

	void display() const;

	void printSeparator() const;

	void addBlock(int max = 1);

	bool checkGameOver();

	void start();
};

#endif //INC_2048GAME_GAME_H
