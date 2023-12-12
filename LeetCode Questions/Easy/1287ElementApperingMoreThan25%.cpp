// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/?envType=daily-question&envId=2023-12-11

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int size = arr.size();
        int twentyfive = size / 4;

        int count = 1;
        for (int i = 1; i < size; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            if (count > twentyfive)
            {
                return arr[i - 1];
            }
        }

        return arr[0];
    }
};