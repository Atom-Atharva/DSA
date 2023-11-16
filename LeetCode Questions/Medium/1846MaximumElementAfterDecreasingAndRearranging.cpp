// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/?envType=daily-question&envId=2023-11-15

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        // Array Size--
        int n = arr.size();

        // Sort Array--
        sort(arr.begin(), arr.end());

        int maximum = 1;
        arr[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] <= 1)
            {
                maximum = max(maximum, arr[i]);
                continue;
            }
            arr[i] = arr[i - 1] + 1;
            maximum = max(maximum, arr[i]);
        }

        return maximum;
    }
};