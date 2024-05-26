// https://www.geeksforgeeks.org/problems/stack-using-two-queues/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

//  The structure of the class is
class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

// Function to push an element into stack using two queues.
void QueueStack ::push(int x)
{
    q1.push(x);
    return;
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    if (q1.size() == 0)
    {
        return -1;
    }

    while (q1.size() > 1)
    {
        q2.push(q1.front());
        q1.pop();
    }

    int element = q1.front();
    q1.pop();

    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }

    return element;
}
