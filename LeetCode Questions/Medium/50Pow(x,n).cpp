// https://leetcode.com/problems/powx-n/

// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n is an integer.
// -104 <= xn <= 104

/********************************* GOOD CONCEPT ******************************************/

#include <iostream>
using namespace std;

// Time Complexity: O(log n)
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long nn = abs(n);
        while (nn > 0)
        {
            if (nn % 2 == 1)
            {
                ans = ans * x;
                nn--;
            }
            else
            {
                x = x * x;
                nn /= 2;
            }
        }
        return (n < 0) ? (double)1 / ans : ans;
    }
};

// Time Limit Exceeded--
// Time Complexity: O(n)
// By- Aditi Gupta
class Solution
{
public:
    double myPow(double x, int n)
    {
        double output = 1;
        if (x == 1)
            return output;
        if (n > 0)
        {
            while (n > 0)
            {
                output = output * x;
                n--;
            }
        }
        else if (n < 0)
        {
            n = -n;
            while (n > 0)
            {
                output = output * x;
                n--;
            }
            output = (1 / output);
        }
        return output;
    }
};