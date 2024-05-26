// https://www.geeksforgeeks.org/problems/queue-using-stack/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;
#include <stack>

class Queue
{
    stack<int> input, output;

public:
    void enqueue(int x)
    {
        input.push(x);
        return;
    }

    int dequeue()
    {
        if (input.empty())
        {
            return -1;
        }

        while (input.size() > 1)
        {
            output.push(input.top());
            input.pop();
        }

        int element = input.top();
        input.pop();

        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }

        return element;
    }
};