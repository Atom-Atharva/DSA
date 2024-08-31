// https://leetcode.com/problems/kth-largest-element-in-a-stream/?envType=daily-question&envId=2024-08-12

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> queue;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (queue.size() >= k)
            {
                if (queue.top() >= nums[i])
                {
                    continue;
                }
                queue.pop();
            }
            queue.push(nums[i]);
        }

        this->k = k;
    }

    int add(int val)
    {
        if (queue.size() >= k)
        {
            if (queue.top() >= val)
            {
                return queue.top();
            }
            queue.pop();
        }
        queue.push(val);

        return queue.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */