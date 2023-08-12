// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

// Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> numbers;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] >= '0' && S[i] <= '9')
            {
                numbers.push(S[i] - '0');
            }
            if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/')
            {
                int num2 = numbers.top();
                numbers.pop();
                int num1 = numbers.top();
                numbers.pop();

                if (S[i] == '+')
                {
                    numbers.push(num1 + num2);
                }
                if (S[i] == '-')
                {
                    numbers.push(num1 - num2);
                }
                if (S[i] == '*')
                {
                    numbers.push(num1 * num2);
                }
                if (S[i] == '/')
                {
                    numbers.push(num1 / num2);
                }
            }
        }

        return numbers.top();
    }
};