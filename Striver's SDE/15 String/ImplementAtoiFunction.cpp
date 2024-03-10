// https : // www.codingninjas.com/studio/problems/981270?topList=striver-sde-sheet-problems

#include <iostream>
using namespace std;
#include <climits>

int createAtoi(string s)
{
    int output = 0;
    bool negative = (s[0] == '-');
    bool seen = (negative);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            seen = true;
            if ((long long)output * 10 + s[i] - '0' > INT_MAX)
            {
                output = INT_MAX;
                continue;
            }

            output = output * 10 + (s[i] - '0');
        }
        else
        {
            if (i == 0 && s[i] == '-')
            {
                continue;
            }
            if (seen)
            {
                break;
            }
        }
    }

    if (output == INT_MAX)
    {
        return (negative) ? INT_MIN : INT_MAX;
    }

    return (negative) ? -1 * output : output;
}