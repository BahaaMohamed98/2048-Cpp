#include "headers/Time.h"

using namespace std;

void Time::start() {
	startTime = std::chrono::steady_clock::now();
}

void Time::end() {
	endTime = std::chrono::steady_clock::now();
	duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
}

int Time::getMinutes() {
	return static_cast<int>(duration.count() / 60);
}

double Time::getSeconds() {
	return static_cast<double>(duration.count() % 60);
}

void Time::printTime(const int &charWidth) {
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