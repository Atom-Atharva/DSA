// https://leetcode.com/problems/merge-intervals/description/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Sort Intervals First
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        // Store Starting and Ending of Interval
        // Compare with current Interval
        int st = intervals[0][0];
        int en = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            int curr_st = intervals[i][0];
            int curr_en = intervals[i][1];

            if (curr_st < st)
            {
                st = curr_st;
                en = max(en, curr_en);
            }
            else if (curr_st <= en)
            {
                en = max(en, curr_en);
            }
            else
            {
                merged.push_back({st, en});
                st = curr_st;
                en = curr_en;
            }
        }
        merged.push_back({st, en});

        return merged;
    }
};