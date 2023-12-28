// https://leetcode.com/problems/path-crossing/?envType=daily-question&envId=2023-12-23

#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
    unordered_map<string, bool> pts;

public:
    bool isPathCrossing(string path, int x = 0, int y = 0)
    {
        string curr = to_string(x) + "," + to_string(y);
        if (pts.count(curr) > 0)
        {
            return true;
        }
        pts[curr] = 1;
        if (path.size() == 0)
        {
            return false;
        }
        if (path[0] == 'N')
        {
            x++;
        }
        else if (path[0] == 'S')
        {
            x--;
        }
        else if (path[0] == 'E')
        {
            y++;
        }
        else
        {
            y--;
        }

        return isPathCrossing(path.substr(1), x, y);
    }
};