// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/?envType=daily-question&envId=2024-01-13

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int minSteps(string s, string t)
    {
        // Cal char in s in smap
        // Cal char in t in tmap
        // Equalise both maps
        //      Calculate Different chars
        //      Make array for Each different char
        //      Binary Search

        vector<int> sMap(26, 0), tMap(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            sMap[s[i] - 'a']++;
            tMap[t[i] - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (tMap[i] < sMap[i])
            {
                count += sMap[i] - tMap[i];
            }
        }

        return count;
    }
};