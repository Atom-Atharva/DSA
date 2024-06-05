// https://leetcode.com/problems/two-sum/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> arr(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            if (arr[l].first + arr[r].first == target)
            {
                return {arr[l].second, arr[r].second};
            }
            else if (arr[l].first + arr[r].first > target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }

        return {-1, -1};
    }
};