// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/?envType=daily-question&envId=2024-06-19

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    int findBouquets(vector<int> &bloomDay, int day, int k)
    {
        int count = 0;
        int consecutives = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] > day)
            {
                count += (consecutives / k);
                consecutives = 0;
            }
            else
            {
                consecutives++;
            }
        }
        count += (consecutives / k);

        return count;
    }

public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (((long long)m * k) > bloomDay.size())
        {
            return -1;
        }

        // Max
        int r = bloomDay[0];
        // Min
        int l = bloomDay[0];

        // Find Min & Max
        for (int i = 0; i < bloomDay.size(); i++)
        {
            r = max(bloomDay[i], r);
            l = min(bloomDay[i], l);
        }

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int bouquets = findBouquets(bloomDay, mid, k);

            if (bouquets < m)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return l;
    }
};