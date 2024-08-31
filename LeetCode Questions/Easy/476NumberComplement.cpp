// https://leetcode.com/problems/number-complement/?envType=daily-question&envId=2024-08-22

#include <iostream>
using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 0)
        {
            return 0;
        }

        int comp = 0;
        int pos = 0;
        while (num > 0)
        {
            if (num % 2 == 0)
            {
                comp += 1 << pos;
            }
            num /= 2;
            pos++;
        }

        return comp;
    }
};