// https://leetcode.com/problems/backspace-string-compare/description/?envType=daily-question&envId=2023-10-19

// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<int> s1, t1;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#')
            {
                if (s1.empty())
                {
                    continue;
                }
                s1.pop();
                continue;
            }

            s1.push(s[i]);
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == '#')
            {
                if (t1.empty())
                {
                    continue;
                }
                t1.pop();
                continue;
            }

            t1.push(t[i]);
        }

        if (s1 == t1)
        {
            return true;
        }
        return false;
    }
};