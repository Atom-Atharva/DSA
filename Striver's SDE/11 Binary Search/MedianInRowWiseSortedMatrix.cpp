// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Solution
{
    int findSmallerOrEqual(vector<vector<int>> &matrix, int num)
    {
        int count = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (num > matrix[i][0])
            {
                continue;
            }
            int low = 0, high = matrix[i].size() - 1;
            int ans = matrix[i].size();
            while (low <= high)
            {
                int mid = (low + high) / 2;

                if (matrix[i][mid] > num)
                {
                    ans = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            count += ans;
        }

        return count;
    }

public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // Find Min and Max Elements
        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < R; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C - 1]);
        }

        // Required Elements smaller than median
        int req = (R * C) / 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            // Search smaller elements from the matrix
            int smallerElements = findSmallerOrEqual(matrix, mid);
            if (smallerElements <= req)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
};