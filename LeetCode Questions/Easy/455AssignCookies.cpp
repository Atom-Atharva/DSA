// https://leetcode.com/problems/assign-cookies/?envType=daily-question&envId=2024-01-01

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        for (int i = 0, j = 0; i < g.size() && j < s.size(); j++)
        {
            if (g[i] <= s[j])
            {
                i++;
                count++;
            }
        }
        return count;
    }
};