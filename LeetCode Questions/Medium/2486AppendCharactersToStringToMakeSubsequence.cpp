// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/?envType=daily-question&envId=2024-06-03

#include <iostream>
using namespace std;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == t[i])
            {
                i++;
            }
        }

        return t.length() - i;
    }
};