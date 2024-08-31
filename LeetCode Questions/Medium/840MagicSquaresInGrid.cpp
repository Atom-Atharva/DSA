// https://leetcode.com/problems/magic-squares-in-grid/?envType=daily-question&envId=2024-08-09

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        if (grid.size() < 3 || grid[0].size() < 3)
        {
            return 0;
        }

        int count = 0;

        // For each 3 X 3 Matrix
        for (int row = 0; row <= grid.size() - 3; row++)
        {
            for (int col = 0; col <= grid[row].size() - 3; col++)
            {
                bool valid = true;
                vector<int> nums(9, 0);

                // Check Distinct 1 to 9
                // Check ROW
                int sum = 15;
                for (int i = row; i < row + 3; i++)
                {
                    int curr = 0;
                    for (int j = col; j < col + 3; j++)
                    {
                        if (grid[i][j] > 9 || grid[i][j] == 0 || nums[grid[i][j] - 1] == 1)
                        {
                            valid = false;
                            break;
                        }
                        nums[grid[i][j] - 1] = 1;
                        curr += grid[i][j];
                    }
                    if (sum != curr || !valid)
                    {
                        valid = false;
                        break;
                    }
                }
                if (!valid)
                {
                    continue;
                }

                // Check COL
                for (int j = col; j < col + 3; j++)
                {
                    int curr = 0;
                    for (int i = row; i < row + 3; i++)
                    {
                        curr += grid[i][j];
                    }
                    if (sum != curr)
                    {
                        valid = false;
                        break;
                    }
                }
                if (!valid)
                {
                    continue;
                }

                // Check RIGHT Diagonal
                int curr = 0;
                for (int i = 0; i < 3; i++)
                {
                    curr += grid[row + i][col + i];
                }
                if (sum != curr)
                {
                    continue;
                }

                // Check LEFT Diagonal
                curr = 0;
                for (int i = 0; i < 3; i++)
                {
                    curr += grid[row + i][col + 2 - i];
                }
                if (curr != sum)
                {
                    continue;
                }

                count++;
            }
        }

        return count;
    }
};