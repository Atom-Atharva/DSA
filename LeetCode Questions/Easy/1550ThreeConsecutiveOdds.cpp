// https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2024-07-01

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] % 2 == 1)
            {
                count++;
                if (count == 3)
                {
                    return true;
                }
            }
            else
            {
                count = 0;
            }
        }

        return false;
    }
};