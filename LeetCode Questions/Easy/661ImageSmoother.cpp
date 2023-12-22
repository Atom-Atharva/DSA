// https://leetcode.com/problems/image-smoother/?envType=daily-question&envId=2023-12-19

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        vector<vector<int>> output(img.size(), vector<int>(img[0].size()));

        // Itterate Over Loop--
        for (int i = 0; i < img.size(); i++)
        {
            for (int j = 0; j < img[i].size(); j++)
            {
                // Find Nearest Cells--
                //      - Count Available Cells.
                //      - SUM Availabale Cells.
                int count = 1, sum = img[i][j];

                // T - TL - L
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    sum += img[i - 1][j - 1] + img[i - 1][j] + img[i][j - 1];
                    count += 3;
                }
                else if (i - 1 >= 0)
                {
                    sum += img[i - 1][j];
                    count++;
                }
                else if (j - 1 >= 0)
                {
                    sum += img[i][j - 1];
                    count++;
                }

                // B - BR - R
                if (i + 1 < img.size() && j + 1 < img[i].size())
                {
                    sum += img[i + 1][j + 1] + img[i + 1][j] + img[i][j + 1];
                    count += 3;
                }
                else if (i + 1 < img.size())
                {
                    sum += img[i + 1][j];
                    count++;
                }
                else if (j + 1 < img[i].size())
                {
                    sum += img[i][j + 1];
                    count++;
                }

                // TR and BL
                if (i + 1 < img.size() && j - 1 >= 0)
                {
                    sum += img[i + 1][j - 1];
                    count++;
                }
                if (i - 1 >= 0 && j + 1 < img[i].size())
                {
                    count++;
                    sum += img[i - 1][j + 1];
                }

                // Edit to Output matrix--
                output[i][j] = sum / count;
            }
        }
        return output;
    }
};