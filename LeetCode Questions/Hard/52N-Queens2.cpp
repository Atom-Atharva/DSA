// https://leetcode.com/problems/n-queens-ii/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    bool checkPosition(vector<vector<int>> &board, int row, int col)
    {
        for (int i = row - 1, j = col - 1, k = col + 1; i >= 0; i--, j--, k++)
        {
            // Up
            if (board[i][col] == 1)
            {
                return false;
            }

            // Left Diagonal
            if (j >= 0 && board[i][j] == 1)
            {
                return false;
            }

            // Right Diagonal
            if (k < board.size() && board[i][k] == 1)
            {
                return false;
            }
        }

        return true;
    }

    void nQueenSolutions(vector<vector<int>> &board, int row, int &solution)
    {
        // Base Case--
        if (row == board.size())
        {
            solution++;
            return;
        }

        for (int i = 0; i < board.size(); i++)
        {
            // Possible Possition--
            if (checkPosition(board, row, i))
            {
                board[row][i] = 1;
                nQueenSolutions(board, row + 1, solution);
                board[row][i] = 0;
            }
        }

        return;
    }

public:
    int totalNQueens(int n)
    {
        vector<vector<int>> board(n, vector<int>(n, 0));

        int solution = 0;
        nQueenSolutions(board, 0, solution);

        return solution;
    }
};