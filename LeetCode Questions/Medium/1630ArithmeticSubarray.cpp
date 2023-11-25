// https://leetcode.com/problems/arithmetic-subarrays/description/?envType=daily-question&envId=2023-11-23

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> ans;

        for (int i = 0; i < l.size(); i++)
        {
            // Range of Subarray--
            int st = l[i];
            int en = r[i];

            // Subarray--
            vector<int> temp;
            for (int i = st; i <= en; i++)
            {
                temp.push_back(nums[i]);
            }

            // Sort Subarray--
            sort(temp.begin(), temp.end());

            // Check AP--
            bool res = true;
            for (int i = 1; i < temp.size(); i++)
            {
                if (temp[i] - temp[i - 1] != temp[1] - temp[0])
                {
                    res = false;
                    break;
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};