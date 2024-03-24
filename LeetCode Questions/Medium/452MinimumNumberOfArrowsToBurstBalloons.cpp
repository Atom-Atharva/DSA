// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=daily-question&envId=2024-03-18

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Method - Overlapping (Merge) Intervals
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int arrows = 0;

        // Sort point array
        sort(points.begin(), points.end());

        int st = points[0][0];
        int en = points[0][1];

        // Travel throught points to cal max common points
        for (int i = 1; i < points.size(); i++)
        {
            // No Overlapping
            if (points[i][0] > en)
            {
                arrows++;
                st = points[i][0];
                en = points[i][1];
            }
            else
            {
                en = min(en, points[i][1]);
            }
        }
        arrows++;

        return arrows;
    }
};