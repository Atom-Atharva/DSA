// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/?envType=daily-question&envId=2024-04-08

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int zeros = 0;
        int ones = 0;

        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == 0)
            {
                zeros++;
            }
            else
            {
                ones++;
            }
        }

        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (sandwiches[i] == 0)
            {
                if (zeros > 0)
                {
                    zeros--;
                }
                else
                {
                    return ones;
                }
            }
            else
            {
                if (ones > 0)
                {
                    ones--;
                }
                else
                {
                    return zeros;
                }
            }
        }

        return 0;
    }
};