// https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

// Using Next Smaller and Prev Smaller Element--
class Solution
{
public:
    const int MOD = 1000000007;

    int sumSubarrayMins(std::vector<int> &arr)
    {
        int n = arr.size();
        stack<int> s1, s2;
        vector<long long> left(n), right(n, n);

        // Calculate left boundaries
        for (int i = 0; i < n; ++i)
        {
            while (!s1.empty() && arr[s1.top()] > arr[i])
            {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }

        // Calculate right boundaries
        for (int i = n - 1; i >= 0; --i)
        {
            while (!s2.empty() && arr[s2.top()] >= arr[i])
            {
                s2.pop();
            }
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }

        // Calculate the final sum
        long long result = 0;
        for (int i = 0; i < n; ++i)
        {
            result = (result + arr[i] * left[i] * right[i]) % MOD;
        }

        return static_cast<int>(result);
    }
};
// Brute Force--
// TLE O(N^2)
/*
class Solution
{
    int M = 1e9 + 7;

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int minElement = arr[i];
            for (int j = i; j < arr.size(); j++)
            {
                minElement = min(minElement, arr[j]);
                sum = (sum + minElement) % M;
            }
        }

        return sum;
    }
};
*/