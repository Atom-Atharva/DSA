// https://leetcode.com/problems/pascals-triangle/

#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++)
        {
            if (i == 0)
            {
                triangle.push_back({1});
                continue;
            }

            vector<int> row(i + 1);
            for (int j = 0; j < i + 1; j++)
            {
                int up1 = 0, up2 = 0;

                if (j - 1 >= 0)
                {
                    up1 = triangle[i - 1][j - 1];
                }
                if (j < triangle[i - 1].size())
                {
                    up2 = triangle[i - 1][j];
                }

                row[j] = up1 + up2;
            }
            triangle.push_back(row);
        }

        return triangle;
    }
};