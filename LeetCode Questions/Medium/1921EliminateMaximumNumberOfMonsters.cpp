// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/?envType=daily-question&envId=2023-11-07

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        // Number Of Monsters--
        int n = dist.size();

        // Time To Reach CITY--
        vector<int> time;
        for (int i = 0; i < n; i++)
        {
            int duration = dist[i] / speed[i];
            int rem = dist[i] % speed[i];
            if (rem > 0)
            {
                duration++;
            }

            time.push_back(duration);
        }

        // Sort time--
        sort(time.begin(), time.end());

        // Killing Time--
        int timer = 0;
        int kills = 0;
        for (int i = 0; i < n; i++)
        {
            if (timer >= time[i])
            {
                break;
            }
            kills++;
            timer++;
        }

        return kills;
    }
};