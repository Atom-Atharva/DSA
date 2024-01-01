// https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    int findString(vector<vector<char>> &mat, string target, int i, int j)
    {
        // Base Case--
        if (target.size() == 1 && target[0] == mat[i][j])
        {
            return 1;
        }
        if (mat[i][j] == 0)
        {
            return 0;
        }
        if (target[0] != mat[i][j])
        {
            return 0;
        }

        char temp = mat[i][j];
        mat[i][j] = 0;
        // Move Right
        int right = (j + 1 < mat[0].size()) ? findString(mat, target.substr(1), i, j + 1) : 0;

        // Move Left
        int left = (j - 1 >= 0) ? findString(mat, target.substr(1), i, j - 1) : 0;

        // Move Down
        int down = (i - 1 >= 0) ? findString(mat, target.substr(1), i - 1, j) : 0;

        // Move Up
        int up = (i + 1 < mat.size()) ? findString(mat, target.substr(1), i + 1, j) : 0;

        mat[i][j] = temp;
        // Return Count
        return right + left + down + up;
    }

public:
    int findOccurrence(vector<vector<char>> &mat, string target)
    {
        // Iterate over matrix
        int count = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                // If target[0]==matrix[element]
                if (target[0] == mat[i][j])
                {
                    // Backtrack target
                    // Exist, then count++.
                    count += findString(mat, target, i, j);
                }
            }
        }

        // Return count
        return count;
    }
};