// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/?envType=daily-question&envId=2024-09-02

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        int sum = 0;
        for (int i = 0; i < chalk.size(); i++)
        {
            sum += chalk[i];
        }

        k = k % sum;
        for (int i = 0; i < chalk.size(); i++)
        {
            if (k < chalk[i])
            {
                return i;
            }
            k -= chalk[i];
        }

        return -1;
    }
};