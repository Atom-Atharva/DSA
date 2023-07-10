// https://leetcode.com/problems/put-marbles-in-bags/

// You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.

// Divide the marbles into the k bags according to the following rules:

// No bag is empty.
// If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
// If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
// The score after distributing the marbles is the sum of the costs of all the k bags.

// Return the difference between the maximum and minimum scores among marble distributions.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {

        // Calculate Pair Sum--
        int *arr = new int[weights.size() - 1];
        for (int i = 0; i < weights.size() - 1; i++)
        {
            arr[i] = weights[i] + weights[i + 1];
        }

        // Sort pair sum array--
        sort(arr, arr + weights.size() - 1);

        // For Minimum Sum--
        long long min = 0;
        for (int i = 0; i < k - 1; i++)
        {
            min += arr[i];
        }

        // For Maximum Sum--
        long long max = 0;
        for (int i = 0; i < k - 1; i++)
        {
            max += arr[weights.size() - 2 - i];
        }

        // Return Difference--
        return max - min;
    }
};