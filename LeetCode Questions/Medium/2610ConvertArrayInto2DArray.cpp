// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/?envType=daily-question&envId=2024-01-02

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> output;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq.count(nums[i]) == 0)
            {
                if (output.size() < 1)
                {
                    output.push_back({nums[i]});
                }
                else
                {
                    output[0].push_back(nums[i]);
                }
            }
            else
            {
                if (output.size() < freq[nums[i]] + 1)
                {
                    output.push_back({nums[i]});
                }
                else
                {
                    output[freq[nums[i]]].push_back(nums[i]);
                }
            }
            freq[nums[i]]++;
        }

        return output;
    }
};