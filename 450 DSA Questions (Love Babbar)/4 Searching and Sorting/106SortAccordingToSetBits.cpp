// https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Time Complexity: O(nlogn)
class Solution
{
    static bool comp(int a, int b)
    {
        // Built In Function which returns no of set bits.
        return __builtin_popcount(a) > __builtin_popcount(b);
    }

public:
    void sortBySetBitCount(int arr[], int n)
    {
        // Stable Sort preserves the order in which they are present in the original array at time of conflict.
        stable_sort(arr, arr + n, comp);

        return;
    }
};

// Time Limit Exceeded.
class Solution
{
public:
    static int countSetBits(int num)
    {
        int count = 0;
        while (num > 0)
        {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    static bool compare(pair<int, int> a, pair<int, int> b)
    {
        int countA = countSetBits(a.first);
        int countB = countSetBits(b.first);

        if (countA == countB)
        {
            return a.second < b.second; // Maintain original order for equal set bit counts
        }

        return countA > countB; // Sort in descending order of set bit counts
    }

    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int, int>> brr;
        for (int i = 0; i < n; i++)
        {
            brr.push_back({arr[i], i});
        }

        sort(brr.begin(), brr.end(), compare);

        for (int i = 0; i < n; i++)
        {
            arr[i] = brr[i].first;
        }

        return;
    }
};

// Time Limit Exceeded.
class Comparator
{
public:
    bool operator()(pair<int, pair<int, int>> x1, pair<int, pair<int, int>> x2)
    {
        if (x1.first == x2.first)
        {
            return x1.second.second < x2.second.second;
        }
        return x1.first > x2.first;
    }
};

class Solution
{
    int countSetBits(int a)
    {
        int count = 0;
        while (a > 0)
        {
            if (a & 1)
            {
                count++;
            }
            a = a >> 1;
        }

        return count;
    }

public:
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int, pair<int, int>>> brr;

        for (int i = 0; i < n; i++)
        {
            pair<int, pair<int, int>> p;
            p.first = countSetBits(arr[i]);
            p.second = {arr[i], i};

            brr.push_back(p);
        }

        sort(brr.begin(), brr.end(), Comparator());

        for (int i = 0; i < n; i++)
        {
            arr[i] = brr[i].second.first;
        }

        return;
    }
};