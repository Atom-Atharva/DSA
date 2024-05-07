// https://leetcode.com/problems/subarrays-with-k-different-integers/description/?envType=daily-question&envId=2024-03-30

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

// Intiution:
//  - Find atmost(k)-atmost(k-1) == exactly(k)
class Solution
{
    int atmost(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return 0;
        }

        unordered_map<int, int> umap;
        int count = 0;
        int right = 0, left = 0;
        while (right < nums.size())
        {
            umap[nums[right]]++;
            if (umap.size() > k)
            {
                umap[nums[left]]--;
                if (umap[nums[left]] == 0)
                {
                    umap.erase(nums[left]);
                }
                left++;
                umap[nums[right]]--;
            }
            else
            {
                count += right - left + 1;
                right++;
            }
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};