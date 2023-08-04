// https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1

// Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of the only set bit. If there are 0 or more than 1 set bit the answer should be -1. Position of  set bit '1' should be counted starting with 1 from LSB side in binary representation of the number.

#include <iostream>
using namespace std;

class Solution
{
public:
    int findPosition(int N)
    {
        if (N == 0)
        {
            return -1;
        }

        int pos = 1;
        while (N > 0)
        {
            if (N % 2 != 0)
            {
                N = N >> 1;
                break;
            }
            N = N >> 1;
            pos++;
        }

        if (N == 0)
        {
            return pos;
        }

        return -1;
    }
};