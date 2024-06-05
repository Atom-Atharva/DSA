// https://www.geeksforgeeks.org/problems/sort-a-stack/1

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
    stack<int> helper;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        stack<int> temp;
        while (!helper.empty() && helper.top() < top)
        {
            temp.push(helper.top());
            helper.pop();
        }
        helper.push(top);
        while (!temp.empty())
        {
            helper.push(temp.top());
            temp.pop();
        }
    }

    while (!helper.empty())
    {
        s.push(helper.top());
        helper.pop();
    }

    return;
}