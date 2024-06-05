#ifndef INC_2048GAME_GAMETIME_H
#define INC_2048GAME_GAMETIME_H

#include <chrono>
#include <iomanip>
#include <iostream>

class GameTime {
private:
	std::chrono::steady_clock::time_point startTime, endTime;
	std::chrono::seconds duration;
public:
	void start();

	void stop();

	int getMinutes();

	double getSeconds();

	void printTime(const int &charWidth);
};

#endif //INC_2048GAME_GAMETIME_H