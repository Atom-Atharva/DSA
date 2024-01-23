// https://leetcode.com/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <map>

// USING MAP
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // Base Case
        if (nums.size() == 0)
        {
            return 0;
        }

        // Insert Into MAP
        map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++;
        }

        vector<int> arr;
        for (auto itr : umap)
        {
            arr.push_back(itr.first);
        }

        int ans = 0;
        int count = 1;
        int prev = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == prev + 1)
            {
                count++;
            }
            else
            {
                ans = max(ans, count);
                count = 1;
            }
            prev = arr[i];
        }

        return max(ans, count);
    }
};

// TLE
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // Insert Into MAP
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++;
        }

        // On Iteration of umap
        // Use Find Method --> O(1).

        // For Each element check for its greter concecutive elements
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int k = nums[i] + 1;
            int concecutive = 1;
            while (umap[k])
            {
                concecutive++;
                k++;
            }

            ans = max(ans, concecutive);
        }

        return ans;
    }
};