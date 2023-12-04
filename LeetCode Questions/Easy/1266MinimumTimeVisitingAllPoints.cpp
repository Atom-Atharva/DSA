// https://leetcode.com/problems/minimum-time-visiting-all-points/description/?envType=daily-question&envId=2023-12-03

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        // Initial Coordinates--
        pair<int, int> coord;
        coord.first = points[0][0];
        coord.second = points[0][1];

        // Calculate Time--
        int time = 0;
        for (int i = 1; i < points.size(); i++)
        {
            time += max(abs(points[i][0] - coord.first), abs(points[i][1] - coord.second));

            coord.first = points[i][0];
            coord.second = points[i][1];
        }

        return time;
    }
};