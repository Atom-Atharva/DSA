// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/?envType=daily-question&envId=2024-08-03

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        return target == arr;
    }
};