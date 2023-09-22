// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/?envType=daily-question&envId=2023-09-18

// You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

// A row i is weaker than a row j if one of the following is true:

// The number of soldiers in row i is less than the number of soldiers in row j.
// Both rows have the same number of soldiers and i < j.
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        // Insert Soldiers with Rows--
        vector<pair<int, int>> soldiers;
        for (int i = 0; i < mat.size(); i++)
        {
            int soldier = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    break;
                }
                soldier++;
            }

            soldiers.push_back({soldier, i});
        }

        // Sort Soldiers--
        sort(soldiers.begin(), soldiers.end());

        // K Rows--
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(soldiers[i].second);
        }

        return ans;
    }
};