// https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Comp
{
    unordered_map<int, int> &freq;

public:
    Comp(unordered_map<int, int> &freq) : freq(freq) {}

    bool operator()(int a, int b)
    {
        if (freq[a] == freq[b])
        {
            return a > b;
        }
        return freq[a] < freq[b];
    }
};

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        sort(nums.begin(), nums.end(), Comp(freq));

        return nums;
    }
};