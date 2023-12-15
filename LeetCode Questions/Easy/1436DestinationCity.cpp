// https://leetcode.com/problems/destination-city/description/?envType=daily-question&envId=2023-12-15

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, bool> points;
        for (int i = 0; i < paths.size(); i++)
        {
            points[paths[i][0]] = 1;
        }

        for (int i = 0; i < paths.size(); i++)
        {
            if (points.count(paths[i][1]) == 0)
            {
                return paths[i][1];
            }
        }

        return "";
    }
};