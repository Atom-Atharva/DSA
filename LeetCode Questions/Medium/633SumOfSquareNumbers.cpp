// https://leetcode.com/problems/sum-of-square-numbers/description/?envType=daily-question&envId=2024-06-17

#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        // Binary Search
        int st = 0, en = sqrt(c);
        while (st <= en)
        {
            if ((long long)st * st + (long long)en * en == c)
            {
                return true;
            }
            else if ((long long)st * st + (long long)en * en < c)
            {
                st++;
            }
            else
            {
                en--;
            }
        }
        return false;
    }
};