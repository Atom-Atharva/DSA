// https://leetcode.com/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;
#include <climits>
#include <vector>

class MinStack
{
    vector<pair<int, int>> arr;
    int curr;
    int minimum;

public:
    MinStack()
    {
        curr = -1;
        minimum = INT_MAX;
    }

    void push(int val)
    {
        if (arr.size() == curr + 1)
        {
            arr.push_back({});
        }
        curr++;
        arr[curr].first = val;
        arr[curr].second = min(minimum, val);
        minimum = min(minimum, val);
    }

    void pop()
    {
        if (arr[curr].first == minimum)
        {
            if (curr - 1 < 0)
            {
                minimum = INT_MAX;
            }
            else
            {
                minimum = arr[curr - 1].second;
            }
        }
        curr--;
    }

    int top()
    {
        return arr[curr].first;
    }

    int getMin()
    {
        return arr[curr].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */