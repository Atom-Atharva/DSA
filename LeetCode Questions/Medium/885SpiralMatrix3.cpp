// https://leetcode.com/problems/spiral-matrix-iii/?envType=daily-question&envId=2024-08-08

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> path;

        // Direction
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Distance
        int row = rStart, col = cStart;
        int distance = 0;
        int rotate = 0;
        int curr = 0;

        // Condition --> If Size == rows * cols THEN RETURN.
        while (path.size() < (rows * cols))
        {
            // Increase Distance
            if (curr % 2 == 0)
            {
                distance++;
            }

            int x = direction[curr][0], y = direction[curr][1];
            for (int i = 0; i < distance; i++)
            {
                // Add Valid Coordinate
                if (row >= 0 && row < rows && col >= 0 && col < cols)
                {
                    path.push_back({row, col});
                }

                // Move to Next Coordinate
                row = row + x;
                col = col + y;
            }
            curr = (curr + 1) % 4;
        }

        return path;
    }
};