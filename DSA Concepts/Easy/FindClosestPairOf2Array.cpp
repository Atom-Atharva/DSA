// https://practice.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Solution
{
public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x)
    {
        int i = 0, j = m - 1;
        int closest = INT_MAX;
        vector<int> pair(2);
        while (i < n && j >= 0)
        {
            int sum = arr[i] + brr[j];
            if (abs(x - closest) > abs(x - sum))
            {
                closest = sum;
                pair[0] = arr[i];
                pair[1] = brr[j];
            }

            if (sum > x)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return pair;
    }
};