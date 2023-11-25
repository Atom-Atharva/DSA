// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/?envType=daily-question&envId=2023-11-25

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        // Calculate Prefix Sum--
        int sum = 0;
        vector<int> arr;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            arr.push_back(sum);
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int rightSum = sum - arr[i];
            int leftSum = arr[i];

            int rightDiff = rightSum - (nums[i] * (nums.size() - 1 - i));
            int leftDiff = leftSum - (i * nums[i]);

            ans.push_back(rightDiff + leftDiff);
        }

        return ans;
    }
};