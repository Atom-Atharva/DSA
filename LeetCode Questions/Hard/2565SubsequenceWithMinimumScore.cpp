#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int minimumScore(string s, string t)
    {
        // Filling DP from back
        int k = t.size() - 1;
        vector<int> dp(t.size(), -1);
        for (int i = s.size() - 1; i >= 0 && k >= 0; i--)
        {
            if (s[i] == t[k])
            {
                dp[k--] = i;
            }
        }

        int res = k + 1;
        for (int i = 0, j = 0; i < s.size() && j < t.size() && res > 0; i++)
        {
            if (s[i] == t[j])
            {
                for (; k < t.size() && dp[k] <= i; k++)
                    ;
                res = min(res, k - (++j));
            }
        }

        return res;
    }
};