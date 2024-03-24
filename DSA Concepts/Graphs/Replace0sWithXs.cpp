// https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void dfsForOs(vector<vector<char>> &mat, int n, int m, int row, int col, vector<vector<int>> &visited, vector<vector<char>> &output)
    {
        visited[row][col] = 1;
        output[row][col] = 'O';

        int pos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto itr : pos)
        {
            int nX = row + itr[0];
            int nY = col + itr[1];

            if (nX >= 0 && nX < n && nY >= 0 && nY < m && !visited[nX][nY] && mat[nX][nY] == 'O')
            {
                dfsForOs(mat, n, m, nX, nY, visited, output);
            }
        }
        return;
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> visited(n, vector<int>(m, 0));

        vector<vector<char>> output(n, vector<char>(m, 'X'));

        // Check Boundaries
        // Check Rows
        for (int j = 0; j < m; j++)
        {
            if (!visited[0][j] && mat[0][j] == 'O')
            {
                dfsForOs(mat, n, m, 0, j, visited, output);
            }
            if (!visited[n - 1][j] && mat[n - 1][j] == 'O')
            {
                dfsForOs(mat, n, m, n - 1, j, visited, output);
            }
        }
        // Check Cols
        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] && mat[i][0] == 'O')
            {
                dfsForOs(mat, n, m, i, 0, visited, output);
            }
            if (!visited[i][m - 1] && mat[i][m - 1] == 'O')
            {
                dfsForOs(mat, n, m, i, m - 1, visited, output);
            }
        }

        return output;
    }
};