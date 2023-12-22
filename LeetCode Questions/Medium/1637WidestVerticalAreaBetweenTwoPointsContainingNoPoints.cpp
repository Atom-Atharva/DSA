// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=daily-question&envId=2023-12-21

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        // Sort Coordinates According to x-axis.
        sort(points.begin(), points.end());

        // Difference between Concecutive Points.
        int width = 0;
        for (int i = 1; i < points.size(); i++)
        {
            int curr = points[i][0] - points[i - 1][0];
            width = (width < curr) ? curr : width;
        }

        return width;
    }
};