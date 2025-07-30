#include <bits/stdc++.h>
using namespace std;
class Player
{
private:
    char symbol;
    string name;

public:
    Player(char sym = 'X', string n = "Player X") : symbol(sym), name(n) {}

    char getSymbol() const { return symbol; }
    string getName() const { return name; }
};

class Board
{
private:
    char grid[3][3];
    int filledCells;

public:
    Board() : filledCells(0)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                grid[i][j] = ' ';
            }
        }
    }

    void drawBoard() const
    {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "| ";
            for (int j = 0; j < 3; j++)
            {
                cout << grid[i][j] << " | ";
            }
            cout << endl
                 << "-------------" << endl;
        }
    }

    // Method to check if a move is valid
    bool isValidMove(int row, int col) const
    {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ');
    }

    // Method to make a move
    void makeMove(int row, int col, char symbol)
    {
        if (isValidMove(row, col))
        {
            grid[row][col] = symbol;
            filledCells++;
        }
    }

    // Method to check for a win
    bool checkWin(char symbol) const
    {
        // Check rows
        for (int i = 0; i < 3; i++)
        {
            if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol)
            {
                return true;
            }
        }

        // Check columns
        for (int i = 0; i < 3; i++)
        {
            if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)
            {
                return true;
            }
        }

        // Check diagonals
        if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol)
        {
            return true;
        }
        if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)
        {
            return true;
        }

        return false;
    }

    bool isFull() const
    {
        return filledCells == 9;
    }

    int getFilledCellsCount() const
    {
        return filledCells;
    }
};

class TicTacToe
{
private:
    Board board;
    Player players[2];
    int currentPlayerIndex;

public:
    TicTacToe() : currentPlayerIndex(0)
    {
        players[0] = Player('X', "Player X");
        players[1] = Player('O', "Player O");
    }

    Player &getCurrentPlayer()
    {
        return players[currentPlayerIndex];
    }

    void switchTurn()
    {
        currentPlayerIndex = (currentPlayerIndex + 1) % 2;
    }

    void play()
    {
        int row, col;
        cout << "Welcome to Tic-Tac-Toe!" << endl;

        while (!board.isFull())
        {
            // Display the board
            board.drawBoard();

            Player &currentPlayer = getCurrentPlayer();

            // Get valid input
            while (true)
            {
                cout << currentPlayer.getName() << " (" << currentPlayer.getSymbol()
                     << "), enter row (1-3) and column (1-3): ";
                cin >> row >> col;
                row--;
                col--;

                if (board.isValidMove(row, col))
                {
                    break;
                }
                else
                {
                    cout << "Invalid move. Try again." << endl;
                }
            }

            board.makeMove(row, col, currentPlayer.getSymbol());

            if (board.checkWin(currentPlayer.getSymbol()))
            {
                board.drawBoard();
                cout << currentPlayer.getName() << " wins!" << endl;
                return;
            }

            switchTurn();
        }

        board.drawBoard();
        cout << "It's a draw!" << endl;
    }
};

int main()
{
    // Creating game object
    TicTacToe game;

    // Starting the game
    game.play();
    return 0;
}