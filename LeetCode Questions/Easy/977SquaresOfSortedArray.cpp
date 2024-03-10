// https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Time Complexity: O(n)
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans;
        int i = 0, j = nums.size() - 1;

        while (i <= j)
        {
            if (abs(nums[i]) < abs(nums[j]))
            {
                ans.push_back(nums[j] * nums[j]);
                j--;
            }
            else
            {
                ans.push_back(nums[i] * nums[i]);
                i++;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Time Complexity: O(nlogn)
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[i] * nums[i]);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
