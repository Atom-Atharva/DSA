// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxCount = 0;
        int count = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < s.length(); i++)
        {
            if (umap.count(s[i]))
            {
                i = umap[s[i]] + 1;
                maxCount = max(maxCount, count);
                count = 0;
                umap.clear();
            }
            count++;
            umap[s[i]] = i;
        }

        maxCount = max(maxCount, count);

        return maxCount;
    }
};