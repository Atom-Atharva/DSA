// https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=daily-question&envId=2024-01-17

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> umap;

        for (int i = 0; i < arr.size(); i++)
        {
            umap[arr[i]]++;
        }

        unordered_map<int, bool> freq;
        for (auto itr : umap)
        {
            if (freq[itr.second])
            {
                return false;
            }
            freq[itr.second] = 1;
        }

        return true;
    }
};