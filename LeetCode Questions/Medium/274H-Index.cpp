// https://leetcode.com/problems/h-index/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        // Sort array
        sort(citations.begin(), citations.end());

        // Iterate from back
        int hIndex = 0;
        for (int i = citations.size() - 1; i >= 0; i--)
        {
            // Find max H-Index
            if (citations[i] <= citations.size() - i)
            {
                hIndex = max(citations[i], hIndex);
            }
            else
            {
                hIndex = max(hIndex, (int)citations.size() - i);
            }
        }

        return hIndex;
    }
};