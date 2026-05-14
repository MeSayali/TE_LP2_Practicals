#include <iostream>
using namespace std;

// Function to print board
void printSolution(int **board, int n) {

    cout << endl;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (board[i][j] == 1) {
                cout << "Q ";
            }
            else {
                cout << ". ";
            }
        }

        cout << endl;
    }

    cout << endl;
}

// Function to check whether queen can be placed safely
bool isSafe(int row, int col, int **board, int n) {

    // Check left side of current row
    for (int i = 0; i < col; i++) {

        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {

        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower-left diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {

        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to solve N Queens using Backtracking
bool solveNQueens(int **board, int col, int n) {

    // Base Case
    if (col >= n) {

        cout << "Final Solution Found:\n";

        printSolution(board, n);

        return true;
    }

    // Try placing queen in every row
    for (int i = 0; i < n; i++) {

        // Check safe position
        if (isSafe(i, col, board, n)) {

            // Place Queen
            board[i][col] = 1;

            cout << "Placed Queen at Position (" 
                 << i << "," << col << ")\n";

            printSolution(board, n);

            // Recursive call for next column
            if (solveNQueens(board, col + 1, n)) {

                return true;
            }

            // Backtracking
            board[i][col] = 0;

            cout << "Backtracking from Position (" 
                 << i << "," << col << ")\n";

            printSolution(board, n);
        }
    }

    return false;
}

int main() {

    int n;

    cout << "Enter the board size (N): ";
    cin >> n;

    // Dynamic 2D Array
    int **board = new int*[n];

    for (int i = 0; i < n; i++) {

        board[i] = new int[n];

        for (int j = 0; j < n; j++) {

            board[i][j] = 0;
        }
    }

    // Solve the problem
    if (!solveNQueens(board, 0, n)) {

        cout << "No Solution Exists\n";
    }

    // Free memory
    for (int i = 0; i < n; i++) {

        delete[] board[i];
    }

    delete[] board;

    return 0;
}