// https://leetcode.com/problems/maximum-total-importance-of-roads/description/?envType=daily-question&envId=2024-06-28

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> degrees(n, 0);
        for (int i = 0; i < roads.size(); i++)
        {
            degrees[roads[i][0]]++;
            degrees[roads[i][1]]++;
        }

        priority_queue<int> queue;
        for (int i = 0; i < n; i++)
        {
            queue.push(degrees[i]);
        }

        long long sum = 0;
        int value = n;
        while (!queue.empty())
        {
            sum += ((long long)value * queue.top());
            queue.pop();
            value--;
        }

        return sum;
    }
};