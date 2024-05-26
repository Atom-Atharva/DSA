// https://leetcode.com/problems/k-th-smallest-prime-fraction/description/?envType=daily-question&envId=2024-05-10

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// Method:
// 1. Two Pointers for Fraction
// 2. Min Heap

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> fract;

        int l = 0, r = arr.size() - 1;
        while (l < r)
        {
            fract.push({(double)arr[l] / arr[r], {arr[l], arr[r]}});
            l++;
            if (l == r)
            {
                l = 0;
                r--;
            }
        }

        vector<int> output(2);
        while (k > 0)
        {
            if (k == 1)
            {
                output[0] = fract.top().second.first;
                output[1] = fract.top().second.second;
            }
            k--;
            fract.pop();
        }

        return output;
    }
};