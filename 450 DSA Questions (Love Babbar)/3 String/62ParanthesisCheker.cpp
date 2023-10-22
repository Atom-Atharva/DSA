// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
// For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

// Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> b;

        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] == '{' || x[i] == '[' || x[i] == '(')
            {
                b.push(x[i]);
            }
            else
            {
                if (b.empty())
                {
                    return false;
                }

                if (x[i] == ')' && b.top() == '(')
                {    
                    b.pop();
                }
                else if (x[i] == ']' && b.top() == '[')
                {
                    b.pop();
                }
                else if (x[i] == '}' && b.top() == '{')
                {
                    b.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (b.empty())
        {
            return true;
        }
        return false;
    }
};