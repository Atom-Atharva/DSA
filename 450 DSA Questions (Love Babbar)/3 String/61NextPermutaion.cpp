// https://practice.geeksforgeeks.org/problems/next-permutation5226/1

// Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Hint For the Problem--

// 1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
// 2. Find the largest index l greater than k such that a[k] < a[l].
// 3. Swap the value of a[k] with that of a[l].
// 4. Reverse the sequence from a[k + 1] up to and including the final element a[n].

class Solution
{
public:
    vector<int> nextPermutation(int n, vector<int> arr)
    {
        int ind = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i + 1] > arr[i])
            {
                ind = i;
                break;
            }
        }
        if (ind == -1)
        {
            reverse(arr.begin(), arr.end());
        }
        else
        {
            for (int i = n - 1; i >= ind; i--)
            {
                if (arr[i] > arr[ind])
                {
                    swap(arr[i], arr[ind]);
                    break;
                }
            }
            reverse(arr.begin() + ind + 1, arr.end());
        }
        return arr;
    }
};