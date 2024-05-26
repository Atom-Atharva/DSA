// https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    bool binarySearch(vector<int> &matrix, int l, int r, int x)
    {
        while (l <= r)
        {
            int mid = (r + l) / 2;
            if (matrix[mid] == x)
            {
                return true;
            }
            else if (matrix[mid] > x)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return false;
    }

public:
    // Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int>> matrix, int n, int m, int x)
    {
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] > x)
            {
                return false;
            }
            if (matrix[i][m - 1] < x)
            {
                continue;
            }
            bool searchKey = binarySearch(matrix[i], 0, m - 1, x);
            if (searchKey)
            {
                return true;
            }
        }
        return false;
    }
};