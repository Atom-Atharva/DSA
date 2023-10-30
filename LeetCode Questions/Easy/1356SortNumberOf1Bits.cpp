// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/?envType=daily-question&envId=2023-10-30

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    int countSetBits(int a)
    {
        int count = 0;
        while (a > 0)
        {
            if (a & 1 == 1)
            {
                count++;
            }
            a /= 2;
        }

        return count;
    }

public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<pair<int, int>> brr;

        for (int i = 0; i < arr.size(); i++)
        {
            pair<int, int> p;
            p.first = countSetBits(arr[i]);
            p.second = arr[i];

            brr.push_back(p);
        }

        sort(brr.begin(), brr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = brr[i].second;
        }

        return arr;
    }
};