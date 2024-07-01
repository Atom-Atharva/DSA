// https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-06-21

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int sumWOG = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            if (grumpy[i] == 0)
            {
                sumWOG += customers[i];
            }
        }

        int maxRelaxation = 0;
        for (int i = 0; i < customers.size() - minutes + 1; i++)
        {
            int relaxation = 0;
            for (int j = i; j < i + minutes; j++)
            {
                if (grumpy[j] == 1)
                {
                    relaxation += customers[j];
                }
            }

            maxRelaxation = max(maxRelaxation, relaxation);
        }

        return (sumWOG + maxRelaxation);
    }
};