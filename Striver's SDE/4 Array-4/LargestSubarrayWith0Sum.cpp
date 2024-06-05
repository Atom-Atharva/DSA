// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        unordered_map<int, int> umap;

        vector<int> sum;
        sum.push_back(0);
        umap[0] = 0;
        for (int i = 0; i < n; i++)
        {
            int num = sum[sum.size() - 1] + A[i];
            sum.push_back(num);

            if (umap.count(num) == 0)
            {
                umap[num] = i + 1;
            }
        }

        int maxCount = 0;
        for (int i = 0; i < n + 1; i++)
        {
            maxCount = max(maxCount, (i - umap[sum[i]]));
        }

        return maxCount;
    }
};