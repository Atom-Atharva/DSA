// https://practice.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1

// You are given a stack St of N integers and an element X. You have to insert X at the bottom of the given stack.

#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    stack<int> insertAtBottom(stack<int> St, int X)
    {
        stack<int> temp;
        while (!St.empty())
        {
            temp.push(St.top());
            St.pop();
        }

        St.push(X);
        while (!temp.empty())
        {
            St.push(temp.top());
            temp.pop();
        }

        return St;
    }
};