// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

// Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// *Time Complexity: O(n^3)
class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        vector<vector<int>> output;

        // Sort the array--
        sort(arr.begin(), arr.end());

        // Fix two numbers and find pair sum using 2 pointers--
        for (int i = 0; i < arr.size() - 3; i++)
        {
            // Handle Duplicates--
            if (i > 0 && arr[i] == arr[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < arr.size() - 2; j++)
            {
                // Handle Duplicates--
                if (j > i + 1 && arr[j] == arr[j - 1])
                {
                    continue;
                }

                int sum = k - (arr[i] + arr[j]);
                int st = j + 1;
                int en = arr.size() - 1;
                while (st < en)
                {
                    if (arr[st] + arr[en] == sum)
                    {
                        output.push_back({arr[i], arr[j], arr[st], arr[en]});
                        st++;
                        en--;
                        // Handle Duplicates--
                        while (st < en && arr[st] == arr[st - 1])
                            st++;
                        while (st < en && arr[en] == arr[en + 1])
                            en--;
                    }
                    else if (arr[st] + arr[en] > sum)
                    {
                        en--;
                    }
                    else
                    {
                        st++;
                    }
                }
            }
        }

        return output;
    }
};

// !Wrong Method--
// Problem is Duplicate nos. are not handled.
class Solution
{
    void fourSum(vector<int> &arr, int k, vector<vector<int>> &output, vector<int> ans, int pos, int num)
    {
        // Base Case--
        if (k == 0 && num == 4)
        {
            output.push_back(ans);
            return;
        }
        if (k <= 0 || num == 4 || pos == arr.size())
        {
            return;
        }

        // Recursive Call--

        // Handle Duplicates--
        if (num > 0 && pos > 0 && arr[pos] == arr[pos - 1] && ans[num - 1] == arr[pos])
        {
            ans[num] = arr[pos];
            fourSum(arr, k - arr[pos], output, ans, pos + 1, num + 1);
            return;
        }

        // Take--
        ans[num] = arr[pos];
        fourSum(arr, k - arr[pos], output, ans, pos + 1, num + 1);

        // Reject--
        ans[num] = -1;
        fourSum(arr, k, output, ans, pos + 1, num);

        return;
    }

public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        // Output Array--
        vector<vector<int>> output;
        vector<int> ans(4, -1);
        sort(arr.begin(), arr.end());

        // Helper Function--
        fourSum(arr, k, output, ans, 0, 0);

        return output;
    }
};