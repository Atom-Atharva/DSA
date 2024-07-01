// https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> expected(heights);

        sort(expected.begin(), expected.end());

        int count = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (expected[i] != heights[i])
            {
                count++;
            }
        }

        return count;
    }
};