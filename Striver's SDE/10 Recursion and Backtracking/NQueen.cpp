// https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    bool checkPosition(vector<int> &board, int pos, int queen)
    {
        // Check Up
        for (int i = 0; i < board.size() - queen + 1; i++)
        {
            if (board[i] - 1 == pos)
            {
                return false;
            }
        }

        // Check Upper - LeftDiagonals
        int k = pos - 1;
        for (int i = board.size() - queen - 1; i >= 0; i--)
        {
            if (k < 0)
            {
                break;
            }
            if (board[i] - 1 == k)
            {
                return false;
            }
            k--;
        }

        // Check Upper - RightDiagonals
        k = pos + 1;
        for (int i = board.size() - queen - 1; i >= 0; i--)
        {
            if (k == board.size())
            {
                break;
            }
            if (board[i] - 1 == k)
            {
                return false;
            }
            k++;
        }

        return true;
    }

    void nQueen(vector<vector<int>> &comb, vector<int> &board, int n)
    {
        // Base Case
        if (n == 0)
        {
            comb.push_back(board);
            return;
        }
        for (int i = 0; i < board.size(); i++)
        {
            if (checkPosition(board, i, n))
            {
                board[board.size() - n] = i + 1;
                nQueen(comb, board, n - 1);
                board[board.size() - n] = -1;
            }
        }
        return;
    }

public:
    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> comb;
        vector<int> board(n, -1);
        nQueen(comb, board, n);
        return comb;
    }
};