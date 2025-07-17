# Tic-Tac-Toe Game with agent

## Overview

This project implements a console-based **Tic-Tac-Toe** game where the player competes against an agent. The game dynamically updates the board, checks for winners, and ensures valid moves.

---

## How the agent works
The agent uses a **Minimax algorithm** to determine the best move. It will be always playing as 'O', while the player plays as 'X'. The agent evaluates all possible moves and chooses the one that maximizes its chances of winning while minimizing the player's chances.
### Agent decision:
The agent will play the move that minimizes the score. 

### Scoring system:
- Agent win: -10 + depth  
- Agent tie: 0
- Player win: 10 - depth

**Note** that by using this, the smallest value will be the best chance for the agent winning.
Using this scoring system turns the agent into a better player if compared to an agent that only uses -1,0,1 as scores.

---

## How to Run

### Prerequisites

- A C++ compiler (e.g., g++, clang++).

### Steps to Run:

1. **Clone or Download:** Ensure all required files (`Source.cpp`, `Board.cpp`, `Board.h`, `Bot.cpp`, `Bot.h`, `Node.cpp`, `Node.h`) are in the same directory.
2. **Compile the Program:**
   ```bash
   ./compile.sh
   ```
   This script compiles the source files into an executable named `TicTacToe`.
3. **Run the Game:**
    ```bash
    ./TicTacToe
    ```

## How to Play

1. Start the game, and the board will be displayed.
2. Enter your move from 1 to 9 corresponding to the board positions:
   ```
   1 | 2 | 3
   ---------
   4 | 5 | 6
   ---------
   7 | 8 | 9
   ```
3. The agent will make its move after yours.
4. The game continues until a player wins or the board is full (resulting in a tie).
5. The game will announce the winner or if it's a tie.

## Notes
- Invalid moves are ignored.
