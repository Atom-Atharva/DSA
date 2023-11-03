// https://leetcode.com/problems/build-an-array-with-stack-operations/?envType=daily-question&envId=2023-11-03

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> ans;

        for (int i = 1, j = 0; i <= n && j < target.size(); i++)
        {
            // If i is Smaller than Required Element--
            if (target[j] > i)
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            // If we Found the Element--
            else if (target[j] == i)
            {
                ans.push_back("Push");
                j++;
            }
        }

        return ans;
    }
};