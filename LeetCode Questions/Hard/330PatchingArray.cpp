// https://leetcode.com/problems/patching-array/?envType=daily-question&envId=2024-06-16

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        // Store Position of Current Element
        int index = 0;

        vector<int> result;

        // Greedy Approach
        // Check for new Number to add
        long long int sum = 0;
        while (sum < n)
        {
            if (index == nums.size())
            {
                result.push_back(sum + 1);
                sum += sum + 1;
                continue;
            }
            if (sum + 1 < nums[index])
            {
                result.push_back(sum + 1);
                sum += sum + 1;
            }
            else
            {
                result.push_back(nums[index]);
                sum += nums[index];
                index++;
            }
        }
        while (index < nums.size())
        {
            result.push_back(nums[index]);
            index++;
        }

        return ((result.size() - nums.size()) > 0) ? (result.size() - nums.size()) : 0;
    }
};