// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/?envType=daily-question&envId=2024-07-02

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++)
        {
            umap[nums1[i]]++;
        }

        vector<int> ans;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (umap.count(nums2[i]) > 0 && umap[nums2[i]] > 0)
            {
                ans.push_back(nums2[i]);
                umap[nums2[i]]--;
            }
        }

        return ans;
    }
};