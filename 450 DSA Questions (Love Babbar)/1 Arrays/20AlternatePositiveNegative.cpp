// https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

// Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
// Note: Array should start with a positive number and 0 (zero) should be considered a positive element.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        vector<int> positive, negative;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
            {
                positive.push_back(arr[i]);
            }
            else
            {
                negative.push_back(arr[i]);
            }
        }

        int pos = 0;
        int neg = 0;
        int curr = 0;
        while (pos < positive.size() && neg < negative.size())
        {
            if (curr % 2 == 0)
            {
                arr[curr] = positive[pos];
                pos++;
            }
            else
            {
                arr[curr] = negative[neg];
                neg++;
            }
            curr++;
        }
        while (pos < positive.size())
        {
            arr[curr++] = positive[pos++];
        }
        while (neg < negative.size())
        {
            arr[curr++] = negative[neg++];
        }

        return;
    }
};