# Tic-Tac-Toe Game with agent

## Overview

This project implements a console-based **Tic-Tac-Toe** game where the player competes against an agent. The game dynamically updates the board, checks for winners, and ensures valid moves.

---

## Features

- **Interactive Gameplay:** Play against an agent that responds after every move.
- **Dynamic Board:** The board updates in real-time with each move.
- **Winner Detection:** The game announces the winner or declares a tie.
- **Input Validation:** Handles invalid moves gracefully.

---

## How to Run

### Prerequisites
- A C++ compiler (e.g., g++, clang++).

### Steps to Run:
1. **Clone or Download:** Ensure all required files (`main.cpp`, `Board.cpp`, `Board.h`, `Bot.cpp`, `Bot.h`, `Node.cpp`, `Node.h`) are in the same directory.
2. **Compile the Program:**
   ```bash
   g++ main.cpp Board.cpp Bot.cpp Node.cpp -o TicTacToe

## How to Play

1. Start the game, and the board will be displayed.
2. Enter your move as two numbers: the row (`x`) and column (`y`), separated by a space (e.g., `1 2`).
3. The bot will respond with its move.
4. Continue playing until:
    - A player aligns three symbols (row, column, or diagonal).
    - The board is full, resulting in a tie.

## Notes
- Replace `system("cls")` with `system("clear")` if using Linux/Mac.
- Invalid moves are ignored.
