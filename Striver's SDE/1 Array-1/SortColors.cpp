// https://leetcode.com/problems/sort-colors/description/

#include <iostream>
using namespace std;
#include <vector>

// Code Sample(Runtime : 0ms)

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 1)
            {
                mid++;
                continue;
            }
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
                continue;
            }
            if (nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int red = 0, white = 0, blue = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                red++;
            }
            if (nums[i] == 1)
            {
                white++;
            }
            if (nums[i] == 2)
            {
                blue++;
            }
        }

        int i = 0;
        while (red != 0)
        {
            nums[i] = 0;
            red--;
            i++;
        }
        while (white != 0)
        {
            nums[i] = 1;
            white--;
            i++;
        }
        while (blue != 0)
        {
            nums[i] = 2;
            blue--;
            i++;
        }

        return;
    }
};