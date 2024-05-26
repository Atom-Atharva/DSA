// https://leetcode.com/problems/reverse-pairs/description/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Method 2:
// 1. Merge Sort
// 2. While Having 2 Sorted Array --> Calculate Pairs
// 3. Merge 2 Arrays.

class Solution
{
    void merge(vector<int> &nums, int low, int mid, int high, int &reversePairsCount)
    {
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && nums[i] > 2 * (long long)nums[j])
            {
                j++;
            }
            reversePairsCount += j - (mid + 1);
        }
        int size = high - low + 1;
        vector<int> temp(size, 0);
        int left = low, right = mid + 1, k = 0;
        while (left <= mid && right <= high)
        {
            if (nums[left] < nums[right])
            {
                temp[k++] = nums[left++];
            }
            else
            {
                temp[k++] = nums[right++];
            }
        }
        while (left <= mid)
        {
            temp[k++] = nums[left++];
        }
        while (right <= high)
        {
            temp[k++] = nums[right++];
        }
        int m = 0;
        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int> &nums, int low, int high, int &reversePairsCount)
    {
        if (low >= high)
        {
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid + 1, high, reversePairsCount);
        merge(nums, low, mid, high, reversePairsCount);
    }

public:
    int reversePairs(vector<int> &nums)
    {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size() - 1, reversePairsCount);
        return reversePairsCount;
    }
};

// Wrong Answer: Not Handled the negative integers.
class Solution2
{
    int findPairs(vector<pair<int, int>> &nums, int l, int r, int key, int k)
    {
        int index = l;
        while (l <= r)
        {
            if (l == r)
            {
                index = l;
                break;
            }

            int mid = (l + r) / 2;
            if (nums[mid].first <= key)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        int pairs = 0;
        for (int i = index; i < nums.size(); i++)
        {
            if (nums[i].second > k)
            {
                pairs++;
            }
        }

        return pairs;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        vector<pair<int, int>> elements;
        for (int i = 0; i < nums.size(); i++)
        {
            elements.push_back({nums[i], i});
        }
        // Sort Descending Order
        sort(elements.begin(), elements.end(), greater<pair<int, int>>());

        int totalPairs = 0;
        for (int i = 0; i < elements.size(); i++)
        {
            int num = elements[i].first / 2;
            if (elements[i].first % 2 == 0)
            {
                num = num - 1;
            }

            if (num < elements[elements.size() - 1].first)
            {
                continue;
            }

            int pairs = findPairs(elements, i + 1, elements.size() - 1, num, elements[i].second);
            totalPairs += pairs;
        }

        return totalPairs;
    }
};