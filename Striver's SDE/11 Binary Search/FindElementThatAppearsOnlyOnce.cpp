// https://www.geeksforgeeks.org/problems/element-appearing-once2552/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;

// User function template for C++
class Solution
{
public:
    int search(int A[], int N)
    {
        int st = 0, en = N - 1;
        while (st < en)
        {
            int mid = (st + en) / 2;
            if ((mid % 2 == 0 && A[mid] == A[mid + 1]) || (mid % 2 == 1 && A[mid] == A[mid - 1]))
            {
                st = mid + 1;
            }
            else
            {
                en = mid;
            }
        }
        return A[st];
    }
};