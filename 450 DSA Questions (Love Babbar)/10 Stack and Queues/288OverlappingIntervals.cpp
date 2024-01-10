// https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1

#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
    {
        vector<vector<int>> merged;

        sort(intervals.begin(), intervals.end());

        stack<int> open, close;
        open.push(intervals[0][0]);
        close.push(intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++)
        {
            int st = intervals[i][0];
            int en = intervals[i][1];

            // Merge Intervals--
            if (st <= close.top())
            {
                int newOpen = min(open.top(), st);

                open.pop();
                open.push(newOpen);

                int newClose = max(close.top(), en);

                close.pop();
                close.push(newClose);
            }
            else
            {
                merged.push_back({open.top(), close.top()});
                open.pop();
                close.pop();

                open.push(st);
                close.push(en);
            }
        }
        merged.push_back({open.top(), close.top()});

        return merged;
    }
};