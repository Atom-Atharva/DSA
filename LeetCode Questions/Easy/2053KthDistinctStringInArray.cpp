// https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=daily-question&envId=2024-08-05

#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> umap;
        for (int i = 0; i < arr.size(); i++)
        {
            umap[arr[i]]++;
        }

        string s = "";
        for (int i = 0; i < arr.size(); i++)
        {
            if (umap[arr[i]] == 1)
            {
                if (k == 1)
                {
                    s = arr[i];
                }
                k--;
            }
        }

        return s;
    }
};