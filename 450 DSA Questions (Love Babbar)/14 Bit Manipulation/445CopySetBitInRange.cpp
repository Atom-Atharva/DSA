// https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1

// Given two numbers X and Y, and a range [L, R] where 1 <= L <= R <= 32. You have to copy the set bits of 'Y' in the range L to R in 'X'. Return this modified X.

// Note: Range count will be from Right to Left & start from 1.

// ********************* GOOD CONCEPT ************************ //

#include <iostream>
using namespace std;

class Solution
{
public:
    int setSetBit(int x, int y, int l, int r)
    {
        // L to R iteration
        for (int i = l - 1; i < r; i++)
        {
            // Y AND with 1 left shift(<<) from L-1 to R-1 and OR with x
            x = x | (y & (1 << i));
        }

        return x;
    }
};