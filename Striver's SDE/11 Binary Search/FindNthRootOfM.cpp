// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int NthRoot(int n, int m)
    {
        int l = 1;
        int r = m;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            long long result = 1;
            for (int i = 1; i <= n; i++)
            {
                result = result * mid;
                if (result > m)
                {
                    r = mid - 1;
                    break;
                }
            }
            if (result == m)
            {
                return mid;
            }
            if (result < m)
            {
                l = mid + 1;
            }
        }

        return -1;
    }
};