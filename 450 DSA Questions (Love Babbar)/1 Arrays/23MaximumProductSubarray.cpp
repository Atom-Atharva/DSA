// https://practice.geeksforgeeks.org/proble    ms/maximum-product-subarray3604/1

// Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n)
    {
        // Contains Overall maximum--
        long long overallMax = arr[0];
        // Maximum in subarray--
        long long maxMul = arr[0];
        // Minimum in Subarray--
        long long minMul = arr[0];

        for (int i = 1; i < n; i++)
        {
            // Update Minimum and Maximum in subarray--
            if (arr[i] > 0)
            {
                maxMul = max(maxMul * arr[i], (long long)arr[i]);
                minMul = min(minMul * arr[i], (long long)arr[i]);
            }
            if (arr[i] == 0)
            {
                maxMul = arr[i];
                minMul = arr[i];
            }
            if (arr[i] < 0)
            {
                long long temp = maxMul;
                maxMul = max((long long)arr[i], minMul * arr[i]);
                minMul = min((long long)arr[i], temp * arr[i]);
            }

            // Update Overall max--
            overallMax = max(overallMax, maxMul);
        }

        return overallMax;
    }
};