#!/bin/bash
g++ Source.cpp Board.cpp Bot.cpp Node.cpp -o TicTacToe

if [ $? -eq 0 ]; then
    sudo mv TicTacToe ~/.local/bin/ttt
    echo "Compilation successful. Executable moved to /usr/local/bin/ttt"
else
    echo "Compilation failed. Executable not moved."
fi
