// https://www.geeksforgeeks.org/problems/graph-and-vertices/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=graph-and-vertices

#include <iostream>
using namespace std;
#include <math.h>

// User function Template for C++
class Solution
{
public:
    long long count(int n)
    {
        int power = (n * (n - 1)) / 2;
        long long ans = pow(2, power);

        return ans;
    }
};