// https://leetcode.com/problems/magnetic-force-between-two-balls/description/?envType=daily-question&envId=2024-06-20

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Binary Search on DISTANCES Not POSITION
class Solution
{
    bool isPossible(vector<int> &position, int distance, int m)
    {
        int count = 1;
        int prev = position[0];
        for (int i = 1; i < position.size(); i++)
        {
            if (position[i] - prev >= distance)
            {
                count++;
                prev = position[i];
            }
        }
        return count >= m;
    }

public:
    int maxDistance(vector<int> &position, int m)
    {
        // Sort Array
        sort(position.begin(), position.end());

        // Base Case
        if (m == 2)
        {
            return (position[position.size() - 1] - position[0]);
        }

        // Min Dist and Maximum Distance
        int r = position[position.size() - 1] - position[0];
        int l = r;
        for (int i = 1; i < position.size(); i++)
        {
            l = min(l, position[i] - position[i - 1]);
        }

        // Binary Search on Distances
        while (l <= r)
        {
            int mid = (l + r) / 2;

            bool placeAll = isPossible(position, mid, m);

            if (placeAll)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return r;
    }
};