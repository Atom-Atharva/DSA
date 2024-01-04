// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/?envType=daily-question&envId=2024-01-04

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        // Sort Array--
        sort(nums.begin(), nums.end());

        int equals = 1;
        int operations = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            // Calculate Same Elements--
            if (nums[i] != nums[i - 1])
            {
                // Remainder by 3 and 2
                // Add min Operation to answer
                if (equals == 1)
                {
                    return -1;
                }

                operations += equals / 3;
                if (equals % 3 != 0)
                {
                    operations++;
                }
                equals = 1;
            }
            else
            {
                equals++;
            }
        }
        if (equals == 1)
        {
            return -1;
        }

        operations += equals / 3;
        if (equals % 3 != 0)
        {
            operations++;
        }

        return operations;
    }
};