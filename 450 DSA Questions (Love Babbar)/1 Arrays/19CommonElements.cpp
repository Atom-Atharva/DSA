// https://practice.geeksforgeeks.org/problems/common-elements1132/1

// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int> ans;
        unordered_map<int, bool> umap;

        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2 && k < n3)
        {
            if (A[i] == B[j] && B[j] == C[k])
            {
                if (umap.count(A[i]) > 0)
                {
                    i++, j++, k++;
                    continue;
                }
                ans.push_back(A[i]);
                umap[A[i]] = true;
                i++;
                j++;
                k++;
            }
            else
            {
                (A[i] < B[j] && A[i] < C[k]) ? i++ : (B[j] < C[k]) ? j++
                                                                   : k++;
            }
        }

        return ans;
    }
};