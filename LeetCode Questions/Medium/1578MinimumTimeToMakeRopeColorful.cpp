// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2023-12-27

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int cost = 0;

        // Iteration over colors--
        for (int i = 1; i < colors.size(); i++)
        {
            // Color Different--
            if (colors[i] != colors[i - 1])
            {
                continue;
            }

            // Color Same--
            if (neededTime[i] < neededTime[i - 1])
            {
                cost += neededTime[i];
                neededTime[i] = neededTime[i - 1];
            }
            else
            {
                cost += neededTime[i - 1];
            }
        }
        return cost;
    }
};