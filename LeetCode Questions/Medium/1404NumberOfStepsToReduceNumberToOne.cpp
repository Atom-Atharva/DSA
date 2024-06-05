// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2024-05-29

#include <iostream>
using namespace std;
#include <cmath>

class Solution
{
    void addOne(string &s)
    {
        int carry = 1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (carry)
            {
                carry = (1 + (s[i] - '0')) / 2;
                s[i] = ((1 + (s[i] - '0')) % 2) + '0';
            }
            else
            {
                break;
            }
        }
        if (carry)
        {
            s = '1' + s;
        }

        return;
    }

public:
    int numSteps(string s)
    {
        int steps = 0;
        while (s != "1")
        {
            if (s[s.length() - 1] == '1')
            {
                // ADD ONE
                addOne(s);
            }
            else
            {
                s = s.substr(0, s.length() - 1);
            }
            steps++;
        }

        return steps;
    }
};