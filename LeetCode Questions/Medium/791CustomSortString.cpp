// https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    string customSortString(string order, string s)
    {
        vector<int> alpha(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            alpha[s[i] - 'a']++;
        }

        string output = "";

        for (int i = 0; i < order.length(); i++)
        {
            while (alpha[order[i] - 'a'])
            {
                output += order[i];
                alpha[order[i] - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            while (alpha[i])
            {
                output += ('a' + i);
                alpha[i]--;
            }
        }

        return output;
    }
};