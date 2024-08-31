// https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;
#include <algorithm>

class Solution
{
public:
    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int arr[], int n, int x)
    {
        // Sort Array
        sort(arr, arr + n);

        // Itterate on Each Element
        for (int i = 0; i < n; i++)
        {
            int req = x - arr[i];
            // Two Pointer on Remaining
            int st = i + 1;
            int en = n - 1;

            while (st < en)
            {
                if (arr[st] + arr[en] == req)
                {
                    return true;
                }
                else if (arr[st] + arr[en] > req)
                {
                    en--;
                }
                else
                {
                    st++;
                }
            }
        }

        return false;
    }
};