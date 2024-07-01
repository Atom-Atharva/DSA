// https://leetcode.com/problems/find-center-of-star-graph/?envType=daily-question&envId=2024-06-27

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int u1, v1, u2, v2;
        u1 = edges[0][0];
        v1 = edges[0][1];
        u2 = edges[1][0];
        v2 = edges[1][1];

        return (u1 == u2 || u1 == v2) ? u1 : v1;
    }
};