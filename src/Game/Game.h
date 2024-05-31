#ifndef INC_2048GAME_GAME_H
#define INC_2048GAME_GAME_H

#include <iostream>
#include <random>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <thread>

using namespace std;

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

class Game {
private:
	vector<vector<int>> grid;
	int charWidth;
	int titleWidth;
	int gridSize;
public:
	explicit Game(int dimension = 4);

	void logic();

	void display() const;

	void printSeparator() const;

	bool up();

	bool down();

	bool right();

	bool left();

	void addBlock(int max = 1);

	bool checkGameOver();

	void run();
};

#endif //INC_2048GAME_GAME_H
