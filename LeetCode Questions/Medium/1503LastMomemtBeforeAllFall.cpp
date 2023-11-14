// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/?envType=daily-question&envId=2023-11-04

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int maxDist = 0;
        for (int i = 0; i < left.size(); i++)
        {
            maxDist = max(maxDist, left[i]);
        }
        for (int i = 0; i < right.size(); i++)
        {
            maxDist = max(maxDist, n - right[i]);
        }

        return maxDist;
    }
};