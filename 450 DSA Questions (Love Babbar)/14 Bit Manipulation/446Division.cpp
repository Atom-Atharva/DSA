// https://practice.geeksforgeeks.org/problems/division-without-using-multiplication-division-and-mod-operator/1

// Given two integers dividend and divisor. Find the quotient after dividing dividend by divisor without using multiplication, division and mod operator.

#include <iostream>
using namespace std;

/************************ GOOD CONCEPT ********************************/

class Solution
{
public:
    long long divide(long long dividend, long long divisor)
    {
        int sign = 1;
        if (dividend < 0 && divisor < 0)
        {
            sign = 1;
        }
        else if (dividend < 0 || divisor < 0)
        {
            sign = -1;
        }

        dividend = abs(dividend);
        divisor = abs(divisor);

        long long quotient = 0;
        long long rest = 0;

        for (int i = 31; i >= 0; i--)
        {
            if (rest + (divisor << i) <= dividend)
            {
                rest += divisor << i;
                quotient = quotient | (1 << i);
            }
        }

        return (sign < 0) ? -quotient : quotient;
    }
};