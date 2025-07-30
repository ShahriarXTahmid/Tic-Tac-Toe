# Tic-Tac-Toe Game in C++

A simple console-based Tic-Tac-Toe game implemented in C++.

## Features

- Two-player gameplay (Player X vs Player O)
- Interactive console interface
- Win condition checking
- Draw detection
- Input validation
- Clear board display after each move

## How to Play

1. Players take turns entering their moves
2. On your turn, enter the row and column numbers (1-3) where you want to place your symbol
3. The first player to get 3 of their symbols in a row (horizontally, vertically, or diagonally) wins
4. If all 9 squares are filled without a winner, the game ends in a draw

## Getting Started

### Prerequisites

- A C++ compiler (g++, clang++, or MSVC)
- Make (optional, for building with the Makefile)

### Compilation and Running

#### Using g++ directly:
```bash
g++ -o tictactoe main.cpp
./tictactoe

