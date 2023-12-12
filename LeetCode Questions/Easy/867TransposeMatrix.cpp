// https://leetcode.com/problems/transpose-matrix/description/?envType=daily-question&envId=2023-12-10

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        vector<vector<int>> trans(matrix[0].size(), vector<int>(matrix.size()));
        for (int i = 0; i < trans.size(); i++)
        {
            for (int j = 0; j < trans[i].size(); j++)
            {
                trans[i][j] = matrix[j][i];
            }
        }

        return trans;
    }
};