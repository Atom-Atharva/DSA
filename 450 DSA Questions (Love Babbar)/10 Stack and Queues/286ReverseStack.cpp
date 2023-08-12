// https://practice.geeksforgeeks.org/problems/reverse-a-stack/1

// You are given a stack St. You have to reverse the stack using recursion.

#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    void Reverse(stack<int> &St)
    {
        // Base Case--
        if (St.empty())
        {
            return;
        }

        // Take Out last Element from the stack--
        stack<int> temp;
        while (!St.empty())
        {
            temp.push(St.top());
            St.pop();
        }

        int top = temp.top();
        temp.pop();

        while (!temp.empty())
        {
            St.push(temp.top());
            temp.pop();
        }

        // Recursion Call--
        Reverse(St);

        // Place last Element on Reversed Array--
        St.push(top);

        return;
    }
};