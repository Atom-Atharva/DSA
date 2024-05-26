// https://leetcode.com/problems/valid-parentheses/description/

#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> parenthesis;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            {
                parenthesis.push(s[i]);
            }
            else
            {
                if (s[i] == '}')
                {
                    if (!parenthesis.empty() && parenthesis.top() == '{')
                    {
                        parenthesis.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                if (s[i] == ')')
                {
                    if (!parenthesis.empty() && parenthesis.top() == '(')
                    {
                        parenthesis.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                if (s[i] == ']')
                {
                    if (!parenthesis.empty() && parenthesis.top() == '[')
                    {
                        parenthesis.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        if (!parenthesis.empty())
        {
            return false;
        }
        return true;
    }
};