// https://leetcode.com/problems/convert-1d-array-into-2d-array/description/?envType=daily-question&envId=2024-09-01

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        // Base Case
        if (m * n != original.size())
        {
            return {};
        }

        vector<vector<int>> arr(m, vector<int>(n, 0));
        for (int i = 0; i < original.size(); i++)
        {
            arr[i / n][i % n] = original[i];
        }

        return arr;
    }
};