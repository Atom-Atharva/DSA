// https://leetcode.com/problems/time-needed-to-buy-tickets/description/?envType=daily-question&envId=2024-04-09

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int time = 0;
        for (int i = 0; i < tickets.size(); i++)
        {
            if (tickets[i] <= tickets[k])
            {
                time += tickets[i];
            }
            else
            {
                time += tickets[k];
                if (i > k)
                {
                    time--;
                }
            }
        }

        return time;
    }
};