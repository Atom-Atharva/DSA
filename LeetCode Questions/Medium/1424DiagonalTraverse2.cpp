// https://leetcode.com/problems/diagonal-traverse-ii/description/?envType=daily-question&envId=2023-11-22

#include <iostream>
using namespace std;
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

//************* GOOD QUESTION *******************//

// Method 3: Store next Diagonal--
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        // Store Initial Coordinates--
        queue<pair<int, int>> diag;
        diag.push({0, 0});

        vector<int> ans;
        while (!diag.empty())
        {
            pair<int, int> coord = diag.front();
            diag.pop();

            int row = coord.first;
            int col = coord.second;

            // Store Element on diagonal--
            ans.push_back(nums[row][col]);

            // Insert Next Diagonal elements--

            // FIRST DOWN When col is 0--
            if (col == 0 && row + 1 < nums.size() && col < nums[row + 1].size())
            {
                diag.push({row + 1, col});
            }

            // SECOND RIGHT--
            if (col + 1 < nums[row].size())
            {
                diag.push({row, col + 1});
            }
        }

        return ans;
    }
};

// Method 2: Tuple Sorting
// Store in Tuple (sum,row,val) and re-group
// class Solution
// {
//     static bool comparator(tuple<int, int, int> x1, tuple<int, int, int> x2)
//     {
//         // When sum equal--
//         if (get<0>(x1) == get<0>(x2))
//         {
//             // Return in desc of row--
//             return get<1>(x1) > get<1>(x2);
//         }

//         // Return in asc of sum--
//         return get<0>(x1) < get<0>(x2);
//     }

// public:
//     vector<int> findDiagonalOrder(vector<vector<int>> &nums)
//     {
//         vector<tuple<int, int, int>> elements;

//         // Insert into elements--
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = 0; j < nums[i].size(); j++)
//             {
//                 // Insert Tuple into elements--
//                 elements.push_back(make_tuple(i + j, i, nums[i][j]));
//             }
//         }

//         // Sort tuples with custom comparator--
//         sort(elements.begin(), elements.end(), comparator);

//         // Get Values from sorted elements--
//         vector<int> ans;
//         for (int i = 0; i < elements.size(); i++)
//         {
//             ans.push_back(get<2>(elements[i]));
//         }

//         return ans;
//     }
// };

// Method 1: Itteration
// TIme Limit Exceeded--
// class Solution
// {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>> &nums)
//     {
//         vector<int> pointer(nums.size(), 0);

//         int maximum = 0;
//         int maxRow = nums[0].size();
//         vector<int> ans;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             // Update MaxRow--
//             if (maxRow <= nums[i].size())
//             {
//                 maxRow = nums[i].size() + i;
//                 maximum = i;
//             }

//             // Print Left Part--
//             for (int j = i; j >= 0; j--)
//             {
//                 // If Present--
//                 if (pointer[j] < nums[j].size())
//                 {
//                     ans.push_back(nums[j][pointer[j]++]);
//                 }
//             }
//         }

//         // Until Last Element is Printed--
//         while (pointer[maximum] < maxRow)
//         {
//             for (int j = nums.size() - 1; j >= 0; j--)
//             {
//                 // If Present--
//                 if (pointer[j] < nums[j].size())
//                 {
//                     ans.push_back(nums[j][pointer[j]++]);
//                 }
//             }
//         }

//         return ans;
//     }
// };