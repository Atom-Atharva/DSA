// https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2023-11-16

#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <unordered_map>

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        // Convert Binary String into Number--
        vector<int> number;
        unordered_map<int, bool> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = 0;
            for (int j = 0; j < nums[i].size(); j++)
            {
                if (nums[i][j] == '1')
                {
                    num += pow(2, nums[i].length() - j - 1);
                }
            }
            number.push_back(num);
            umap[num] = 1;
        }

        // Find First Missing Number--
        int missing = 0;
        for (int i = 0; i < pow(2, nums[0].length()); i++)
        {
            if (umap.count(i) == 0)
            {
                missing = i;
                break;
            }
        }

        // Convert Into Binary String--
        string ans = "";
        while (missing > 0)
        {
            int rem = missing % 2;
            if (rem == 1)
            {
                ans = '1' + ans;
            }
            else
            {
                ans = '0' + ans;
            }
            missing /= 2;
        }

        while (ans.length() < nums[0].length())
        {
            ans = '0' + ans;
        }
        return ans;
    }
};