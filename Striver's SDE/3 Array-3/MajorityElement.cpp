// https://www.geeksforgeeks.org/problems/majority-element-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;
#include <algorithm>

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        sort(a, a + size);

        int count = 1;
        for (int i = 1; i < size; i++)
        {
            if (a[i - 1] == a[i])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            if (count > size / 2)
            {
                return a[i];
            }
        }
        if (count > size / 2)
        {
            return a[size - 1];
        }
        return -1;
    }
};