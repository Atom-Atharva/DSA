// https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int> &arr)
    {
        for (int i = 1; i < n; i += 2)
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }

        return;
    }
};