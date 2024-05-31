#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	while (true) {
		if ((int) getch() == 224) { // if the first value is esc
			int val = (int) getch();
			cout << "arrow" << val << '\n';
		} else {
			cout << "x\n";
		}
	}
}