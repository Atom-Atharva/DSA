// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/?envType=daily-question&envId=2023-11-08

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        if (sx == fx && sy == fy && t == 1)
        {
            return false;
        }

        if ((sx + t) >= fx && (sy + t >= fy) && (sx - t) <= fx && (sy - t) <= fy)
        {
            return true;
        }
        return false;
    }
};