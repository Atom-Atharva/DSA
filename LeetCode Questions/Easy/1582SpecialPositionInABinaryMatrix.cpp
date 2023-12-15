// https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2023-12-13

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int count = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            // Check on Each Row--
            bool unique = false;
            int col = -1;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    if (!unique)
                    {
                        unique = true;
                        col = j;
                        continue;
                    }
                    else
                    {
                        col = -1;
                        break;
                    }
                }
            }

            // For Each Row check Corresponsing Columns--
            unique = true;
            for (int j = 0; j < mat.size() && col != -1; j++)
            {
                if (j == i)
                {
                    continue;
                }
                if (mat[j][col] == 1)
                {
                    unique = false;
                    break;
                }
            }

            if (unique && col != -1)
            {
                count++;
            }
        }

        return count;
    }
};