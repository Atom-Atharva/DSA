// https://leetcode.com/problems/count-number-of-nice-subarrays/?envType=daily-question&envId=2024-06-22

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        vector<int> prefix(nums.size(), 0);

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 1)
            {
                sum++;
            }
            prefix[i] = sum;
        }

        unordered_map<int, int> freq;
        freq[0] = 1;

        int count = 0;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (prefix[i] >= k)
            {
                count += freq[prefix[i] - k];
            }
            freq[prefix[i]]++;
        }

        return count;
    }
};