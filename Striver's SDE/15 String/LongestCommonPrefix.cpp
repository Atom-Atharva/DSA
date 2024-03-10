// https://leetcode.com/problems/longest-common-prefix/description/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string output = "";
        sort(strs.begin(), strs.end());

        for (int i = 0; i < strs[0].length(); i++)
        {
            if (strs[0][i] != strs[strs.size() - 1][i])
            {
                break;
            }
            output = output + strs[0][i];
        }

        return output;
    }
};