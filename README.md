# Tic-Tac-Toe Game with AI Bot

## Overview

This project implements a console-based **Tic-Tac-Toe** game where the player competes against an AI bot. The game dynamically updates the board, checks for winners, and ensures valid moves.

---

## Features

- **Interactive Gameplay:** Play against an AI bot that responds after every move.
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

