# 2048 Game in C++

Welcome to the 2048 Game in C++! This project is a console-based version of the popular 2048 puzzle game.

## Features

- Classic 2048 game mechanics
- Simple, intuitive controls
- Console-based UI with a clean layout
- Color-coded tiles for a better gaming experience

## Requirements

- C++ compiler (e.g., GCC, Clang, MSVC)
- CMake
- Basic knowledge of C++ and command-line interface

## How to Play

1. *Start the Game*:

   Run the executable or compile the source code and execute the program.
2. *Controls*:
   - Use arrow keys to move the tiles up, down, left, or right.
   - Combine tiles of the same number to add them.
   - Try to reach the 2048 tile!

3. *Game Over*:

   The game ends when no more moves are possible.

## Installation

*Clone the Repository*:

```bash
git clone https://github.com/BahaaMohamed98/Console-2048-Game
```

Compile the Source Code:

```bash
g++ .\main.cpp .\Game.cpp .\GameTime.cpp .\helpers.cpp .\Menu.cpp .\MoveHandler.cpp -o 2048 -static -static-libstdc++ -static-libgcc -I src/headers`
```

Run the executable:

```bash
.\2048
```


OR run the `2048.exe` file in the `Build` directory directly using:
```bash
.\Build\2048.exe
```

## Project Structure

main.cpp: Entry point of the game.

- `Game.h`: Contains the game logic and rendering.

- `Menu.h`: Handles the main menu and user inputs.

- `MoveHandler.h`: Manages the movement logic.