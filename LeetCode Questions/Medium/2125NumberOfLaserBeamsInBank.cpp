// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-03

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int beams = 0;
        int prev = 0;
        for (int i = 0; i < bank.size(); i++)
        {
            int curr = 0;
            for (int j = 0; j < bank[i].length(); j++)
            {
                if (bank[i][j] == '1')
                {
                    curr++;
                }
            }
            beams += prev * curr;
            prev = (curr != 0) ? curr : prev;
        }

        return beams;
    }
};