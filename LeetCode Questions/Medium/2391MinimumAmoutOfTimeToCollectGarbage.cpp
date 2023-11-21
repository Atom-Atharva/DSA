// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/?envType=daily-question&envId=2023-11-20

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int M = 0, P = 0, G = 0;
        int countM = 0, countG = 0, countP = 0;
        int dist = 0;
        for (int i = 0; i < garbage.size(); i++)
        {
            if (i > 0)
            {
                dist += travel[i - 1];
            }

            for (int j = 0; j < garbage[i].length(); j++)
            {
                if (garbage[i][j] == 'M')
                {
                    countM++;
                    M = dist;
                }
                if (garbage[i][j] == 'P')
                {
                    countP++;
                    P = dist;
                }
                if (garbage[i][j] == 'G')
                {
                    countG++;
                    G = dist;
                }
            }
        }

        int ans = M + countM + P + countP + G + countG;

        return ans;
    }
};