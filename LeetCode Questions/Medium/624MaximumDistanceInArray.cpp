// https://leetcode.com/problems/maximum-distance-in-arrays/description/?envType=daily-question&envId=2024-08-16

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int distance = 0;

        // Search Min First Then Max
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        int index = -1;
        for (int i = 0; i < arrays.size(); i++)
        {
            if (arrays[i][0] < minimum)
            {
                index = i;
            }
            minimum = min(minimum, arrays[i][0]);
        }
        for (int i = 0; i < arrays.size(); i++)
        {
            if (i == index)
            {
                continue;
            }
            maximum = max(maximum, arrays[i][arrays[i].size() - 1]);
        }

        distance = max(distance, abs(minimum - maximum));

        minimum = INT_MAX;
        maximum = INT_MIN;
        index = -1;
        // Search Max First Then Min
        for (int i = 0; i < arrays.size(); i++)
        {
            if (arrays[i][arrays[i].size() - 1] > maximum)
            {
                index = i;
            }
            maximum = max(maximum, arrays[i][arrays[i].size() - 1]);
        }
        for (int i = 0; i < arrays.size(); i++)
        {
            if (i == index)
            {
                continue;
            }
            minimum = min(minimum, arrays[i][0]);
        }

        distance = max(distance, abs(minimum - maximum));

        return distance;
    }
};