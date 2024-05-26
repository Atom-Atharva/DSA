// https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/description/

#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumNumbers(int num, int k)
    {
        // Base Case
        if (num == 0)
        {
            return 0;
        }
        if (k > num)
        {
            return -1;
        }

        int un = num % 10;
        for (int i = 1; i <= 10; i++)
        {
            int kun = (k * i) % 10;
            if (kun == un)
            {
                if (k * i > num)
                {
                    return -1;
                }
                return i;
            }
        }

        return -1;
    }
};