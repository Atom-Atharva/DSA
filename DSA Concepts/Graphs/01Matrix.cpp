// https://leetcode.com/problems/01-matrix/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// Optimization
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int, int>, int>> levels;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    levels.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        vector<vector<int>> output(m, vector<int>(n, 0));
        while (!levels.empty())
        {
            pair<int, int> ele = levels.front().first;
            int lev = levels.front().second;
            levels.pop();

            output[ele.first][ele.second] = lev;

            int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            for (auto itr : pos)
            {
                int nX = ele.first + itr[0];
                int nY = ele.second + itr[1];

                if (nX >= 0 && nX < mat.size() && nY >= 0 && nY < mat[0].size() && !visited[nX][nY])
                {
                    levels.push({{nX, nY}, lev + 1});
                    visited[nX][nY] = 1;
                }
            }
        }

        return output;
    }
};

// TLE
/*
class Solution
{
    int bfsForOne(vector<vector<int>> &mat, int row, int col)
    {
        vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0));

        // {{row, col}, Level}
        queue<pair<pair<int, int>, int>> level;
        level.push({{row, col}, 0});

        while (!level.empty())
        {
            pair<int, int> ele = level.front().first;
            int lev = level.front().second;

            level.pop();
            visited[ele.first][ele.second] = 1;

            if (mat[ele.first][ele.second] == 0)
            {
                return lev;
            }

            int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            for (auto itr : pos)
            {
                int nX = ele.first + itr[0];
                int nY = ele.second + itr[1];

                if (nX >= 0 && nX < mat.size() && nY >= 0 && nY < mat[0].size() && !visited[nX][nY])
                {
                    level.push({{nX, nY}, lev + 1});
                }
            }
        }

        return -1;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> output(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    int dist = bfsForOne(mat, i, j);
                    output[i][j] = dist;
                }
            }
        }

        return output;
    }
};
*/