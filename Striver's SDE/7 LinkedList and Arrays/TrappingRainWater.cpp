// https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

#include <iostream>
using namespace std;

class Solution
{
    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // Base Case
        if (n <= 2)
        {
            return 0;
        }

        // Max Length from LEFT
        // Max Length from RIGHT
        int left[n], right[n];
        int maxX = 0;
        for (int i = 0; i < n; i++)
        {
            maxX = max(maxX, arr[i]);
            left[i] = maxX;
        }

        maxX = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            maxX = max(maxX, arr[i]);
            right[i] = maxX;
        }

        long long fill = 0;
        for (int i = 0; i < n; i++)
        {
            int water = min(left[i], right[i]) - arr[i];
            if (water < 0)
            {
                water = 0;
            }
            fill += water;
        }

        return fill;
    }
};