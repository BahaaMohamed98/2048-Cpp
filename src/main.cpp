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

template<int gridSize = 4>
class Game {
private:
	int grid[gridSize][gridSize]{};
	int charWidth;
	int titleWidth;
public:
	Game() : charWidth(5) {
		for (int i = 0; i < 2; ++i)
			addBlock(0);
		titleWidth = (gridSize * charWidth) + (charWidth << 1) + 1;
	}

	void logic() {
		while (!checkGameOver()) {
			checkGameOver();
			if ((int) getch() != 224)
				cout << "Invalid\n";
			else
				switch ((int) getch()) {
					case UP:
						up();
						addBlock();
						display();
						break;
					case RIGHT:
						right();
						addBlock();
						display();
						break;
					case LEFT:
						left();
						addBlock();
						display();
						break;
					case DOWN:
						down();
						addBlock();
						display();
					default:
						cout << "Invalid\n";
				}
		}
		cout << "\nGame Over!\n";
	}

	void display() const {
		system("cls");

		cout << setw(titleWidth) << "2048 Game\n\n";

		printSeparator();
		for (auto &x: grid) {
			for (auto &y: x)
				cout << setw(charWidth) << '|' << setw(charWidth) << y;
			cout << setw(charWidth) << '|' << "\n";
			printSeparator();
		}
	}

	void printSeparator() const {
		for (int i = 0; i < charWidth - 1; ++i)
			cout << ' ';
		for (int i = 0; i < gridSize; i++)
			for (int j = 0; j < (charWidth << 1); ++j)
				cout << '-';
		cout << "-\n";
	}

	void up() {
		for (int i = 0; i < gridSize; ++i) {//cols
			for (int j = 1; j < gridSize; ++j) {//rows
				int temp = j;
				while (temp > 0 and grid[temp - 1][i] == 0 and grid[temp][i] != 0)
					swap(grid[temp][i], grid[temp - 1][i]), temp--;
			}
		}
		for (int i = 0; i < gridSize - 1; ++i)
			for (int j = 0; j < gridSize; ++j)
				if (grid[i][j] == 0)
					swap(grid[i][j], grid[i + 1][j]);
				else if (grid[i][j] == grid[i + 1][j])
					grid[i][j] <<= 1, grid[i + 1][j] = 0;
	}

	void down() {
		for (int i = gridSize - 1; i >= 0; --i) {//cols
			for (int j = gridSize - 2; j >= 0; --j) {//rows
				int temp = j;
				while (temp < gridSize and grid[temp + 1][i] == 0 and grid[temp][i] != 0)
					swap(grid[temp][i], grid[temp + 1][i]), temp++;
			}
		}
		for (int i = gridSize - 2; i >= 0; --i)
			for (int j = gridSize - 1; j >= 0; --j)
				if (grid[i + 1][j] == 0)
					swap(grid[i][j], grid[i + 1][j]);
				else if (grid[i + 1][j] == grid[i][j])
					grid[i + 1][j] <<= 1, grid[i][j] = 0;
		display();
	}

	void right() {
		for (int i = gridSize - 1; i >= 0; --i) {
			for (int j = gridSize - 2; j >= 0; --j) {
				int temp = j;
				while ((temp < gridSize - 1) and grid[i][temp + 1] == 0 and grid[i][temp] != 0)
					swap(grid[i][temp + 1], grid[i][temp]), temp++;
			}
		}
		for (int i = gridSize - 1; i >= 0; --i) {
			for (int j = gridSize - 1; j > 0; --j) {
				if (grid[i][j] == 0)
					swap(grid[i][j], grid[i][j - 1]);
				else if (grid[i][j] == grid[i][j - 1])
					grid[i][j] <<= 1, grid[i][j - 1] = 0;
			}
		}
	}

	void left() {
		for (auto &gridRow: grid) {
			for (int j = 1; j < gridSize; ++j) {
				int temp = j;
				while (temp > 0 and gridRow[temp - 1] == 0 and gridRow[temp] != 0)
					swap(gridRow[temp - 1], gridRow[temp]), temp--;
			}
		}
		for (auto &gridRow: grid) {
			for (int j = 1; j < gridSize; ++j) {
				if (gridRow[j - 1] == 0)
					swap(gridRow[j], gridRow[j - 1]);
				else if (gridRow[j] == gridRow[j - 1])
					gridRow[j - 1] <<= 1, gridRow[j] = 0;
			}
		}
	}

	void addBlock(int max = 1) {
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(0, max);
		std::uniform_int_distribution<std::mt19937::result_type> dist7(0, 3);

		int x = 0, y = 0;
		while (grid[x][y] != 0)
			x = (int) dist7(rng), y = (int) dist7(rng);
		grid[x][y] = 2 << dist6(rng);

	}

	bool checkGameOver() {
		for (auto &x: grid)
			for (auto &y: x) {
				if (y == 0)
					return false;
			}
		return true;
	}

	void run() {
		cout << "\033[?25l";
		display();
		logic();
	}
};


int main() {
	Game<4> gg;
	gg.run();
	getch();
}
