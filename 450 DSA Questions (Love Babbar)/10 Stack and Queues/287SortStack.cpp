// https://practice.geeksforgeeks.org/problems/sort-a-stack/1

// Given a stack, the task is to sort it such that the top of the stack has the greatest element.

#include <iostream>
using namespace std;
#include <stack>

// The structure of the class is
class SortedStack
{
public:
    stack<int> s;
    void sort();
};

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort()
{
    // Stack to store sorted elements--
    stack<int> sorted;

    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        stack<int> temp;
        while (!sorted.empty() && sorted.top() < top)
        {
            temp.push(sorted.top());
            sorted.pop();
        }

        sorted.push(top);

        while (!temp.empty())
        {
            sorted.push(temp.top());
            temp.pop();
        }
    }

    while (!sorted.empty())
    {
        s.push(sorted.top());
        sorted.pop();
    }

    return;
}