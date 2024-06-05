#ifndef INC_2048GAME_MOVEHANDLER_H
#define INC_2048GAME_MOVEHANDLER_H

#include <vector>
#include "Game.h"

using namespace std;

class MoveHandler {
private:
	static bool moveUp(class Game &);

	static bool moveDown(class Game &);

	static bool moveRight(class Game &);

	static bool moveLeft(class Game &);

public:
	static bool move(class Game &, int);
};

#endif //INC_2048GAME_MOVEHANDLER_H
