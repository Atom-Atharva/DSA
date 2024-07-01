// https://leetcode.com/problems/ipo/description/?envType=daily-question&envId=2024-06-15

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        // Make Pair
        vector<pair<int, int>> jobs;
        for (int i = 0; i < profits.size(); i++)
        {
            jobs.push_back({capital[i], profits[i]});
        }

        // Sort by Capital(Inc) and Profit(Dec)
        sort(jobs.begin(), jobs.end());

        // Priority Queue on Profits
        priority_queue<int> queue;

        // Greedy Approach
        for (int i = 0, j = 0; i < k; i++)
        {
            // Insert till w < jobs[i].first
            while (j < jobs.size())
            {
                if (w < jobs[j].first)
                {
                    break;
                }

                queue.push(jobs[j].second);
                j++;
            }
            if (queue.empty())
            {
                break;
            }

            // Take out Maximum Profit job
            w += queue.top();
            queue.pop();
        }

        return w;
    }
};