#ifndef INC_2048GAME_MOVEHANDLER_H
#define INC_2048GAME_MOVEHANDLER_H

#include <vector>

using namespace std;

class MoveHandler {
public:
	static bool moveUp(vector<vector<int>> &grid, int &score);

	static bool moveDown(vector<vector<int>> &grid, int &score);

	static bool moveRight(vector<vector<int>> &grid, int &score);

	static bool moveLeft(vector<vector<int>> &grid, int &score);
};

#endif //INC_2048GAME_MOVEHANDLER_H
