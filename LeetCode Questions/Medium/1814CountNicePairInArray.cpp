// https://leetcode.com/problems/count-nice-pairs-in-an-array/?envType=daily-question&envId=2023-11-21

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
    // Modulo 1e9+7;
    // int M = 1000000007;
    int M = 1e9 + 7;

    // Reverse Number--
    int reverse(int num)
    {
        int ans = 0;
        while (num > 0)
        {
            int rem = num % 10;
            ans = ((ans * 10) % M + rem) % M;
            num /= 10;
        }

        return ans;
    }

public:
    int countNicePairs(vector<int> &nums)
    {
        // Create a map storing diff of number with its reverse--
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++)
        {
            int rev = reverse(nums[i]);
            umap[nums[i] - rev]++;
        }

        int count = 0;
        for (auto itr : umap)
        {
            // Count pairs of 2 elements--
            count = (count + ((long long)itr.second * (itr.second - 1)) / 2) % M;
        }

        return count;
    }
};