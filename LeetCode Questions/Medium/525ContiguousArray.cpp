// https://leetcode.com/problems/contiguous-array/?envType=daily-question&envId=2024-03-16

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int subArray_length = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if (sum == 0)
            {
                subArray_length = i + 1;
            }
            else if (mp.find(sum) != mp.end())
            {
                subArray_length = max(subArray_length, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return subArray_length;
    }
};

// TLE
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int maxCount = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int zero = 0;
            int one = 0;

            int count = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] == 0)
                {
                    zero++;
                }
                else
                {
                    one++;
                }
                count++;

                if (zero == one)
                {
                    maxCount = max(maxCount, count);
                }
            }
        }

        return maxCount;
    }
};