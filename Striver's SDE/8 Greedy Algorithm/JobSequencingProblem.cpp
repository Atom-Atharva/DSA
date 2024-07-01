// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

struct comparator
{
    bool operator()(Job &jb1, Job &jb2)
    {
        if (jb1.profit == jb2.profit)
        {
            return jb1.dead < jb2.dead;
        }
        return jb1.profit > jb2.profit;
    }
};

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // All time Slots
        vector<bool> time(n, 0);

        // Sort Jobs on Maximumm Profit, Minimum Deadline
        sort(arr, arr + n, comparator());

        int count = 0;
        int profit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = min(arr[i].dead - 1, n - 1); j >= 0; j--)
            {
                if (time[j] == 0)
                {
                    time[j] = 1;
                    profit += arr[i].profit;
                    count++;
                    break;
                }
            }
        }

        return {count, profit};
    }
};