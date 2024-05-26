// https://leetcode.com/problems/find-lucky-integer-in-an-array/

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        unordered_map<int, int> umap;
        for (auto itr : arr)
        {
            umap[itr]++;
        }

        int largest = -1;
        for (auto itr : umap)
        {
            if (itr.first == itr.second)
            {
                largest = max(largest, itr.first);
            }
        }

        return largest;
    }
};