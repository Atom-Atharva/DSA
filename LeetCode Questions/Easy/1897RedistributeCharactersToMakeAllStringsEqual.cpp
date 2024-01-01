// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/?envType=daily-question&envId=2023-12-30

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        vector<char> character(26, 0);
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                character[words[i][j] - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (character[i] % words.size() != 0)
            {
                return false;
            }
        }

        return true;
    }
};