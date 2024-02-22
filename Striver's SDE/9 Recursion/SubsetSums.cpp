// https://www.geeksforgeeks.org/problems/subset-sums2234/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void subsetSums(vector<int> arr, int N, int pos, int sum, vector<int> &ans)
    {
        // Base Case
        if (pos == N)
        {
            return;
        }

        // Recursive Calls
        // Take or Ignore
        subsetSums(arr, N, pos + 1, sum, ans);
        ans.push_back(sum + arr[pos]);
        subsetSums(arr, N, pos + 1, sum + arr[pos], ans);

        return;
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        ans.push_back(0);
        subsetSums(arr, N, 0, 0, ans);
        return ans;
    }
};