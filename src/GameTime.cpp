#include "GameTime.h"

using namespace std;

void GameTime::start() {
	startTime = std::chrono::steady_clock::now();
}

void GameTime::stop() {
	endTime = std::chrono::steady_clock::now();
	duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
}

int GameTime::getMinutes() {
	return static_cast<int>(duration.count() / 60);
}

double GameTime::getSeconds() {
	return static_cast<double>(duration.count() % 60);
}

void GameTime::printTime(const int &charWidth) {
	int minVal = ((int) getMinutes()), secVal = (int) getSeconds();
	string minutes, seconds;

	if (minVal < 9)
		minutes = "0";
	if (secVal < 9)
		seconds = "0";

	minutes += to_string(minVal);
	seconds += to_string(secVal);

	cout << setw(charWidth) << "Elapsed time: "
	     << setw(2) << minutes << ':'
	     << setw(2) << seconds << 's';
}