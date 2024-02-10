// https: // leetcode.com/problems/daily-temperatures/?envType=daily-question&envId=2024-01-31

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

// Find Next Greater Element
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<pair<int, int>> nxtTemp;
        vector<int> ans(temperatures.size());

        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            while (!nxtTemp.empty() && nxtTemp.top().first <= temperatures[i])
            {
                nxtTemp.pop();
            }
            if (nxtTemp.empty())
            {
                ans[i] = 0;
                nxtTemp.push({temperatures[i], i});
                continue;
            }

            ans[i] = (nxtTemp.top().second - i);
            nxtTemp.push({temperatures[i], i});
        }

        return ans;
    }
};