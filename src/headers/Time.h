#ifndef INC_2048GAME_TIME_H
#define INC_2048GAME_TIME_H

#include <chrono>
#include <iomanip>
#include <iostream>

class Time {
private:
	std::chrono::steady_clock::time_point startTime, endTime;
	std::chrono::seconds duration;
public:
	void start();

	void end();

	int getMinutes();

	double getSeconds();

	void printTime(const int &charWidth);
};

#endif //INC_2048GAME_TIME_H