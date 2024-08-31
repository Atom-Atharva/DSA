// https://leetcode.com/problems/number-of-senior-citizens/?envType=daily-question&envId=2024-08-01

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int count = 0;
        for (int i = 0; i < details.size(); i++)
        {
            int age = (details[i][11] - '0') * 10 + (details[i][12] - '0');
            if (age > 60)
            {
                count++;
            }
        }

        return count;
    }
};