#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int countCompleteDayPairs(vector<int> &hours)
    {
        sort(hours.begin(), hours.end());

        int count = 0;
        for (int i = 0; i < hours.size() - 1; i++)
        {
            for (int j = i + 1; j < hours.size(); j++)
            {
                if ((hours[i] + hours[j]) % 24 == 0)
                {
                    count++;
                }
            }
        }

        return count;
    }
};