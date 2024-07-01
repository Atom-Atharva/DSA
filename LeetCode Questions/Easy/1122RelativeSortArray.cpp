// https://leetcode.com/problems/relative-sort-array/description/?envType=daily-question&envId=2024-06-11

#include <iostream>
using namespace std;
#include <vector>
#include <climits>
#include <algorithm>

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> sorted;
        for (int i = 0; i < arr2.size(); i++)
        {
            for (int j = 0; j < arr1.size(); j++)
            {
                if (arr2[i] == arr1[j])
                {
                    sorted.push_back(arr1[j]);
                    arr1[j] = INT_MAX;
                }
            }
        }

        sort(arr1.begin(), arr1.end());

        for (auto itr : arr1)
        {
            if (itr == INT_MAX)
            {
                break;
            }
            sorted.push_back(itr);
        }

        return sorted;
    }
};