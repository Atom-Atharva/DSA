// https://leetcode.com/problems/walking-robot-simulation/

#include <iostream>
using namespace std;
#include <vector>
#include <set>

// Method:
// 1. Maintain Direction
// 2. Check For Obstacle
// 3. Maintain Maximum Distance

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        // Maintain Direction (Initially North)
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0;

        // Storing Obstacles
        set<pair<int, int>> obs;
        for (int i = 0; i < obstacles.size(); i++)
        {
            obs.insert({obstacles[i][0], obstacles[i][1]});
        }

        // Lets Walk
        int max_distance = 0;
        pair<int, int> pos = {0, 0};

        for (int i = 0; i < commands.size(); i++)
        {
            if (commands[i] == -1)
            {
                direction = (direction + 1) % 4;
                continue;
            }
            else if (commands[i] == -2)
            {
                direction = (direction - 1);
                if (direction < 0)
                {
                    direction = 3;
                }
                continue;
            }

            for (int j = 0; j < commands[i]; j++)
            {
                pair<int, int> nextPos = {pos.first + (1 * directions[direction].first), pos.second + (1 * directions[direction].second)};

                // Check Obstacle
                if (obs.find(nextPos) != obs.end())
                {
                    continue;
                }
                pos = nextPos;
                int distance = (pos.first * pos.first) + (pos.second * pos.second);
                max_distance = max(max_distance, distance);
            }
        }

        return max_distance;
    }
};