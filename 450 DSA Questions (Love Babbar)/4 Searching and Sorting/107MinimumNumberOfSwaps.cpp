// https://practice.geeksforgeeks.org/problems/minimum-swaps/1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        // Form an array.
        vector<int> sorted;
        for (int i = 0; i < nums.size(); i++)
        {
            sorted.push_back(nums[i]);
        }

        // Sort the array.
        sort(sorted.begin(), sorted.end());

        // Form u_map with value:location.
        unordered_map<int, int> umap;
        for (int i = 0; i < sorted.size(); i++)
        {
            umap[sorted[i]] = i;
        }

        int swaps = 0;

        // Find Cycles.
        for (int i = 0; i < nums.size(); i++)
        {
            // Skip.
            if (nums[i] == -1 || nums[i] == sorted[i])
            {
                continue;
            }

            // Cycle Count.
            int cycle = 0;
            int j = i;
            while (nums[j] != -1)
            {
                cycle++;
                int temp = nums[j];
                nums[j] = -1;
                j = umap[temp];
            }
            swaps += cycle - 1;
        }

        return swaps;
    }
};