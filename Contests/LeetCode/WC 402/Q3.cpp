// https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

// DP
class Solution
{
    long long maximumTotalDamage(vector<int> &unique, unordered_map<int, int> &freq, int pos, int prev, vector<long long> &dp)
    {
        // Base Case
        if (pos == unique.size())
        {
            return 0;
        }
        if (unique[pos] + 1 == prev || unique[pos] + 2 == prev)
        {
            return maximumTotalDamage(unique, freq, pos + 1, prev, dp);
        }
        if (dp[pos] != -1)
        {
            return dp[pos];
        }

        // Take
        long long take = (long long)freq[unique[pos]] * unique[pos] + maximumTotalDamage(unique, freq, pos + 1, unique[pos], dp);

        // Ignore
        long long ignore = maximumTotalDamage(unique, freq, pos + 1, prev, dp);

        return dp[pos] = max(take, ignore);
    }

public:
    long long maximumTotalDamage(vector<int> &power)
    {
        unordered_map<int, int> freq;
        vector<int> unique;
        for (int i = 0; i < power.size(); i++)
        {
            if (freq.count(power[i]) == 0)
            {
                unique.push_back(power[i]);
            }

            freq[power[i]]++;
        }

        vector<long long> dp(unique.size(), -1);

        sort(unique.begin(), unique.end(), greater<int>());

        long long maxDamage = maximumTotalDamage(unique, freq, 0, 0, dp);

        return maxDamage;
    }
};