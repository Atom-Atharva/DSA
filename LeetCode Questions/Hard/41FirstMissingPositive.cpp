// https://leetcode.com/problems/first-missing-positive/description/?envType=daily-question&envId=2024-03-26

#include <iostream>
using namespace std;
#include <vector>
#include <set>

// Method 2: Indices as Indicator
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        // Discard non-positive Integers
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0)
            {
                nums[i] = n + 1;
            }
        }

        // Mark Indices Visited
        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]);

            if (num <= n)
            {
                int indices = num - 1;

                nums[indices] = -abs(nums[indices]);
            }
        }

        // Find Missing Number
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }

        // No Missing Found then n+1
        return n + 1;
    }
};

// Method 1: SETS
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        set<int> set;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0 && set.count(nums[i]) == 0)
            {
                set.insert(nums[i]);
            }
        }

        int number = 1;
        for (auto itr : set)
        {
            if (number == itr)
            {
                number++;
            }
            else
            {
                break;
            }
        }

        return number;
    }
};
