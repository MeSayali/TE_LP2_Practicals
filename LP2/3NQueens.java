package Pr4;

import java.util.*;

public class NQueens {

    static int N;

    // Function to print solution
    static void printBoard(int[][] board) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    // Check if safe to place queen
    static boolean isSafe(int[][] board, int row, int col) {

        // Check left side of row
        for (int i = 0; i < col; i++)
            if (board[row][i] == 1)
                return false;

        // Check upper diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;

        // Check lower diagonal
        for (int i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j] == 1)
                return false;

        return true;
    }

    // Backtracking function
    static boolean solveNQ(int[][] board, int col) {
        if (col >= N)
            return true;

        for (int i = 0; i < N; i++) {

            if (isSafe(board, i, col)) {
                board[i][col] = 1;

                if (solveNQ(board, col + 1))
                    return true;

                // Backtrack
                board[i][col] = 0;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter value of N: ");
        N = sc.nextInt();

        int[][] board = new int[N][N];

        if (solveNQ(board, 0)) {
            System.out.println("Solution:");
            printBoard(board);
        } else {
            System.out.println("No solution exists");
        }

        sc.close();
    }
}
