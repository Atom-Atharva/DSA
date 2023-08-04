// https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/

// Given an integer n, calculate the square of a number without using *, / and pow().

#include <iostream>
using namespace std;

/*
    If n is even, it can be written as
    n = 2*x
    n2 = (2*x)2 = 4*x2
    If n is odd, it can be written as
    n = 2*x + 1
    n2 = (2*x + 1)2 = 4*x2 + 4*x + 1
*/

/************************ GOOD CONCEPT ********************************/

class Solution
{
public:
    int square(int n)
    {
        // Base Case.
        if (n == 0)
        {
            return 0;
        }

        // Handle Negative Case.
        if (n < 0)
        {
            n = -n;
        }

        // Get Floor(n/2) using right shift.
        int x = n >> 1;

        // If n is odd
        if (n & 1)
        {
            return ((square(x) << 2) + (x << 2) + 1);
        }
        else
        {
            return square(x) << 2;
        }
    }
};