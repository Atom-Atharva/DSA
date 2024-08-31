// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <iostream>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        for (int i = 0; i < haystack.length(); i++)
        {
            if (haystack[i] != needle[0])
            {
                continue;
            }
            bool found = true;
            for (int j = 0, k = i; j < needle.length(); j++, k++)
            {
                if (needle[j] != haystack[k])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                return i;
            }
        }
        return -1;
    }
};