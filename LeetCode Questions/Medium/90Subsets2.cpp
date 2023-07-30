// https://leetcode.com/problems/subsets-ii/

// Given an integer array nums that may contain duplicates, return all possible
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    void subsets(vector<int> &nums, int pos, vector<vector<int>> &output, int count)
    {
        // Base Case--
        if (pos == nums.size())
        {
            return;
        }

        if (pos > 0 && nums[pos] == nums[pos - 1])
        {
            int temp = 0;

            // Insert in the counts--
            int i = output.size() - 1;
            while (count--)
            {
                vector<int> current = output[i];
                i--;
                current.push_back(nums[pos]);

                output.push_back(current);
                temp++;
            }

            count = temp;
        }
        else
        {
            int temp = 0;
            int n = output.size();

            // Insert in the Existing--
            for (int i = 0; i < n; i++)
            {
                vector<int> current = output[i];
                current.push_back(nums[pos]);

                output.push_back(current);
                temp++;
            }

            count = temp;
        }

        // Recursive Calls--
        subsets(nums, pos + 1, output, count);

        return;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // Output Array--
        vector<vector<int>> output;
        output.push_back({});

        // Sort Nums--
        sort(nums.begin(), nums.end());

        // Helper Function--
        subsets(nums, 0, output, 0);

        // Return output Array--
        return output;
    }
};