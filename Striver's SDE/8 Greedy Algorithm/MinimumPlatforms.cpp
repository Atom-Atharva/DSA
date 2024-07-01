// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        vector<pair<int, int>> train;
        for (int i = 0; i < n; i++)
        {
            train.push_back({arr[i], dep[i]});
        }

        sort(train.begin(), train.end());

        vector<int> platforms;
        for (int i = 0; i < n; i++)
        {
            int arrival = train[i].first;
            int departure = train[i].second;

            bool found = false;
            for (int j = 0; j < platforms.size(); j++)
            {
                if (arrival > platforms[j])
                {
                    platforms[j] = departure;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                platforms.push_back(departure);
            }
        }

        return platforms.size();
    }
};