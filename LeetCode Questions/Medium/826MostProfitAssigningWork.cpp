// https://leetcode.com/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-06-18

#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>
#include <vector>

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        vector<pair<int, int>> work;
        for (int i = 0; i < profit.size(); i++)
        {
            work.push_back({difficulty[i], profit[i]});
        }

        sort(work.begin(), work.end());
        sort(worker.begin(), worker.end());

        priority_queue<int> queue;
        int count = 0;
        for (int i = 0, j = 0; i < worker.size(); i++)
        {
            // Insert works into queue till max difficulty worker can handle
            while (j < work.size() && work[j].first <= worker[i])
            {
                queue.push(work[j].second);
                j++;
            }
            if (!queue.empty())
            {
                count += queue.top();
            }
        }

        return count;
    }
};