// https://www.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int remove_duplicate(vector<int> &arr)
    {
        int i = 1, j = 1;
        while (i < arr.size())
        {
            if (arr[i - 1] == arr[i])
            {
                i++;
                continue;
            }
            arr[j] = arr[i];
            j++;
            i++;
        }

        while (j < i)
        {
            arr.pop_back();
            j++;
        }

        return arr.size();
    }
};