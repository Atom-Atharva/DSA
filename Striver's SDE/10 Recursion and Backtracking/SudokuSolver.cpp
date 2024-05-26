// https://leetcode.com/problems/sudoku-solver/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    bool found = false;

    bool checkPosition(vector<vector<char>> &board, int row, int col, char num)
    {
        // Check Row
        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] == num)
            {
                return false;
            }
        }

        // Check Col
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][col] == num)
            {
                return false;
            }
        }

        // Check Sub-Box
        int stRow = (row / 3) * 3;
        int stCol = (col / 3) * 3;
        for (int i = stRow; i < stRow + 3; i++)
        {
            for (int j = stCol; j < stCol + 3; j++)
            {
                if (board[i][j] == num)
                {
                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board, int row = 0, int col = 0)
    {
        if (found)
        {
            return;
        }
        if (board[row][col] != '.')
        {
            col++;
            if (col == board.size())
            {
                col = 0;
                row++;
            }
            if (row == board.size())
            {
                found = true;
                return;
            }
            solveSudoku(board, row, col);
            return;
        }

        for (int k = 1; k <= 9; k++)
        {
            if (checkPosition(board, row, col, '0' + k))
            {
                board[row][col] = '0' + k;
                solveSudoku(board, row, col);
                if (!found)
                {
                    board[row][col] = '.';
                }
            }
        }
        return;
    }
};