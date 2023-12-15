// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/?envType=daily-question&envId=2023-12-14

#include <iostream>
using namespace std;
#include <vector>

// Optimized on Space--
class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        vector<int> onesRow(grid.size()), onesCol(grid[0].size());
        // Calculate Row 1s and Columns 1s.
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }

        vector<vector<int>> diff(grid.size(), vector<int>(grid[0].size()));
        // Iterate Over Each Element.
        for (int i = 0; i < grid.size(); i++)
        {
            // Make Diff Matrix for Each Element.
            for (int j = 0; j < grid[i].size(); j++)
            {
                diff[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - grid.size() - grid[i].size();
            }
        }

        return diff;
    }
};

// Brute Force--
// class Solution
// {
// public:
//     vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
//     {
//         vector<int> onesRow, onesCol, zerosRow, zerosCol;
//         // Calculate Row 0s and 1s.
//         for (int i = 0; i < grid.size(); i++)
//         {
//             int ones = 0, zeros = 0;
//             for (int j = 0; j < grid[i].size(); j++)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     ones++;
//                 }
//                 else
//                 {
//                     zeros++;
//                 }
//             }
//             onesRow.push_back(ones);
//             zerosRow.push_back(zeros);
//         }
//         // Calculate Col 0s and 1s.
//         for (int i = 0; i < grid[0].size(); i++)
//         {
//             int ones = 0, zeros = 0;
//             for (int j = 0; j < grid.size(); j++)
//             {
//                 if (grid[j][i] == 1)
//                 {
//                     ones++;
//                 }
//                 else
//                 {
//                     zeros++;
//                 }
//             }
//             onesCol.push_back(ones);
//             zerosCol.push_back(zeros);
//         }

//         vector<vector<int>> diff(grid.size(), vector<int>(grid[0].size()));
//         // Iterate Over Each Element.
//         for (int i = 0; i < grid.size(); i++)
//         {
//             // Make Diff Matrix for Each Element.
//             for (int j = 0; j < grid[i].size(); j++)
//             {
//                 diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
//             }
//         }

//         return diff;
//     }
// };