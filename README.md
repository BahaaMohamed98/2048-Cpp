# 2048 Game in C++

Welcome to the 2048 Game in C++! This project is a console-based version of the popular 2048 puzzle game.

## Features

- Classic 2048 game mechanics
- Simple, intuitive controls
- Console-based UI with a clean layout
- Color-coded tiles for a better gaming experience

## Requirements

- A Windows device
- C++ compiler (e.g., GCC, Clang, MSVC)
- Basic knowledge of C++ and command-line interface

## How to Play

1. *Start the Game*:
   
   Run the executable or compile the source code and execute the program.
3. *Controls*:
   - Use arrow keys to move the tiles up, down, left, or right.
   - Combine tiles of the same number to add them.
   - Try to reach the 2048 tile!

4. *Game Over*:
   
   The game ends when no more moves are possible.

## Installation

*Clone the Repository*:
   
   `git clone https://github.com/BahaaMohamed98/Console-2048-Game`
   
   `cd src`
   
Compile the Source Code:

`g++ -o 2048 main.cpp Game/Game.cpp Menu/Menu.cpp Game/Movehandler/MoveHandler.cpp -std=c++17`

Run the Game:

`./2048`

or

Run the `main.exe` file in the `Build` folder

## Project Structure

main.cpp: Entry point of the game.

Game.cpp / Game.h: Contains the game logic and rendering.

Menu.cpp / Menu.h: Handles the main menu and user inputs.

MoveHandler.cpp / MoveHandler.h: Manages the movement logic.

## Future Plans

- Implement settings.
- Implement a main controller class to manage game states.
- Add features like leaderboards and achievements.
- Allow customization of grid size.
