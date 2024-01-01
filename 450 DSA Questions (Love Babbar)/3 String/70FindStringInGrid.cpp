// https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    bool leftUp(vector<vector<char>> &mat, string target, int i, int j)
    {
        for (int l = 0; l < target.size(); l++)
        {
            if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
            {
                return false;
            }
            if (mat[i][j] != target[l])
            {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
    bool leftDown(vector<vector<char>> &mat, string target, int i, int j)
    {
        for (int l = 0; l < target.size(); l++)
        {
            if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
            {
                return false;
            }
            if (mat[i][j] != target[l])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool rightUp(vector<vector<char>> &mat, string target, int i, int j)
    {
        for (int l = 0; l < target.size(); l++)
        {
            if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
            {
                return false;
            }
            if (mat[i][j] != target[l])
            {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    bool rightDown(vector<vector<char>> &mat, string target, int i, int j)
    {
        for (int l = 0; l < target.size(); l++)
        {
            if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
            {
                return false;
            }
            if (mat[i][j] != target[l])
            {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
    bool down(vector<vector<char>> &mat, string target, int i, int j)
    {
        for (int l = 0; l < target.size(); l++)
        {
            if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
            {
                return false;
            }
            if (mat[i][j] != target[l])
            {
                return false;
            }
            i++;
        }
        return true;
    }
    bool up(vector<vector<char>> &mat, string target, int i, int j)
    {
        for (int l = 0; l < target.size(); l++)
        {
            if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
            {
                return false;
            }
            if (mat[i][j] != target[l])
            {
                return false;
            }
            i--;
        }
        return true;
    }
    bool right(vector<vector<char>> &mat, string target, int i, int j)
    {
        for (int l = 0; l < target.size(); l++)
        {
            if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
            {
                return false;
            }
            if (mat[i][j] != target[l])
            {
                return false;
            }
            j++;
        }
        return true;
    }
    bool left(vector<vector<char>> &mat, string target, int i, int j)
    {
        for (int l = 0; l < target.size(); l++)
        {
            if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
            {
                return false;
            }
            if (mat[i][j] != target[l])
            {
                return false;
            }
            j--;
        }
        return true;
    }

    bool findString(vector<vector<char>> &mat, string target, int i, int j)
    {
        // Check all directions--
        bool l = left(mat, target, i, j);
        bool r = right(mat, target, i, j);
        bool u = up(mat, target, i, j);
        bool d = down(mat, target, i, j);
        bool lu = leftUp(mat, target, i, j);
        bool ld = leftDown(mat, target, i, j);
        bool ru = rightUp(mat, target, i, j);
        bool rd = rightDown(mat, target, i, j);

        return l || r || u || d || lu || ld || ru || rd;
    }

public:
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        // Iterate over matrix
        vector<vector<int>> coords;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                // If target[0]==matrix[element]
                if (word[0] == grid[i][j])
                {
                    // Exist, then add coords.
                    if (findString(grid, word, i, j))
                    {
                        coords.push_back({i, j});
                    }
                }
            }
        }

        // Return count
        return coords;
    }
};