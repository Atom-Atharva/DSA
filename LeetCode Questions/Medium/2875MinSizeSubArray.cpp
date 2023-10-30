// https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Solution
{
public:
    int minSizeSubarray(vector<int> &nums, int target)
    {
        int st = 0, en = 0;
        int sum = 0;
        int update = nums[0];
        int minSize = INT_MAX;
        int size = 1;
        while (st < nums.size())
        {
            // st crosses en.
            if (size == 0)
            {
                en = st;
                sum = 0;
                update = nums[st];
                size = 1;
            }
            sum += update;

            // Separately Handled TLE.
            if (size == nums.size() && sum == nums.size())
            {
                return target;
            }

            // Checking Window and updating.
            if (sum == target)
            {
                minSize = min(minSize, size);
                en++;
                size++;
                if (en == nums.size())
                {
                    en = 0;
                }
                update = nums[en];
            }
            else if (sum > target)
            {
                update = -nums[st];
                st++;
                size--;
            }
            else
            {
                en++;
                size++;
                if (en == nums.size())
                {
                    en = 0;
                }
                update = nums[en];
            }
        }

        return (minSize == INT_MAX) ? -1 : minSize;
    }
};