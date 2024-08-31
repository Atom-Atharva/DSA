// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2024-08-06

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < word.length(); i++)
        {
            freq[word[i] - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int clicks = 0;
        for (int i = 0; i < 26; i++)
        {
            int pos = i / 8;
            clicks += freq[i] * (pos + 1);
        }

        return clicks;
    }
};