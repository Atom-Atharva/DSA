// https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> state(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Find Live Neighbours
                int lived = 0;
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    lived = (board[i - 1][j - 1] == 1) ? lived + 1 : lived;
                }
                if (i - 1 >= 0)
                {
                    lived = (board[i - 1][j] == 1) ? lived + 1 : lived;
                }
                if (j - 1 >= 0)
                {
                    lived = (board[i][j - 1] == 1) ? lived + 1 : lived;
                }
                if (i + 1 < m && j - 1 >= 0)
                {
                    lived = (board[i + 1][j - 1] == 1) ? lived + 1 : lived;
                }
                if (i + 1 < m)
                {
                    lived = (board[i + 1][j] == 1) ? lived + 1 : lived;
                }
                if (i + 1 < m && j + 1 < n)
                {
                    lived = (board[i + 1][j + 1] == 1) ? lived + 1 : lived;
                }
                if (j + 1 < n)
                {
                    lived = (board[i][j + 1] == 1) ? lived + 1 : lived;
                }
                if (i - 1 >= 0 && j + 1 < n)
                {
                    lived = (board[i - 1][j + 1] == 1) ? lived + 1 : lived;
                }

                // Change Matrix
                if (lived < 2)
                {
                    state[i][j] = 0;
                }
                if (lived > 3)
                {
                    state[i][j] = 0;
                }
                if (board[i][j] == 1 && (lived == 2 || lived == 3))
                {
                    state[i][j] = 1;
                }
                if (board[i][j] == 0 && lived == 3)
                {
                    state[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = state[i][j];
            }
        }
        return;
    }
};