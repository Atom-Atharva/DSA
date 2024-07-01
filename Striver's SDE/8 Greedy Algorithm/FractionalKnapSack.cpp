// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <iostream>
using namespace std;
#include <algorithm>

// class implemented

struct Item
{
    int value;
    int weight;
};

struct comparator
{
    bool operator()(Item &i1, Item &i2)
    {
        return ((double)i1.value / i1.weight) > ((double)i2.value / i2.weight);
    }
};

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr, arr + n, comparator());

        double profit = 0;
        for (int i = 0; i < n; i++)
        {
            if (w < arr[i].weight)
            {
                profit += ((double)arr[i].value / arr[i].weight) * w;
                break;
            }
            profit += arr[i].value;
            w -= arr[i].weight;
        }

        return profit;
    }
};