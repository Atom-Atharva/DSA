// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meets;
        for (int i = 0; i < n; i++)
        {
            meets.push_back({start[i], end[i]});
        }
        sort(meets.begin(), meets.end());

        int st = meets[0].first;
        int en = meets[0].second;

        int count = 1;
        for (int i = 0; i < n; i++)
        {
            if (meets[i].first <= en)
            {
                if (meets[i].second < en)
                {
                    st = meets[i].first;
                    en = meets[i].second;
                }
            }
            else
            {
                st = meets[i].first;
                en = meets[i].second;
                count++;
            }
        }

        return count;
    }
};