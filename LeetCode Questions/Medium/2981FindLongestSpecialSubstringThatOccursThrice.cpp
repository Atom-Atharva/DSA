// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/

#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    int maximumLength(string s)
    {
        // For Each Substring--
        int maxLen = 0;
        for (int i = 1; i <= s.length(); i++)
        {
            // Check Maximum Possible Length
            unordered_map<string, int> substr;
            for (int j = 0; j < s.length() - i + 1; j++)
            {
                string sub = s.substr(j, i);
                substr[sub]++;
                if (substr[sub] == 3)
                {
                    bool special = true;
                    for (int k = 1; k < sub.size(); k++)
                    {
                        if (sub[k] != sub[k - 1])
                        {
                            special = false;
                        }
                    }
                    if (special)
                    {
                        maxLen = i;
                        break;
                    }
                }
            }
        }

        return (maxLen == 0) ? -1 : maxLen;
    }
};