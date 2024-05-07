// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=daily-question&envId=2024-04-06

#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<char> brac;

        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')')
            {
                if (brac.empty())
                {
                    continue;
                }
                brac.pop();
            }
            if (s[i] == '(')
            {
                brac.push('(');
            }
            s[j] = s[i];
            j++;
        }
        s = s.substr(0, j);
        if (brac.empty())
        {
            return s;
        }

        stack<char> close;

        j = s.length() - 1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                if (close.empty())
                {
                    continue;
                }
                close.pop();
            }
            if (s[i] == ')')
            {
                close.push(')');
            }
            s[j] = s[i];
            j--;
        }
        s = s.substr(j + 1, s.length() - 1 - j);

        return s;
    }
};