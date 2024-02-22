// https://www.codingninjas.com/studio/problems/count-inversions_615

#include <iostream>
using namespace std;

long long getInversions(long long *arr, int n)
{
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }

    return count;
}