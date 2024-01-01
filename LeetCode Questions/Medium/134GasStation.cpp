// https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int resouce = 0, costing = 0;
        int curr = 0, index = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            resouce += gas[i];
            costing += cost[i];

            curr += gas[i] - cost[i];
            if (curr < 0)
            {
                curr = 0;
                index = i + 1;
            }
        }

        return (resouce >= costing) ? index : -1;
    }
};