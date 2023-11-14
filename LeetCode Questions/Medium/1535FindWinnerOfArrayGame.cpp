// https://leetcode.com/problems/find-the-winner-of-an-array-game/?envType=daily-question&envId=2023-11-04

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int wins = 0;
        int curr = 0;
        int next = 1;

        while (wins < k && next < arr.size())
        {
            if (arr[curr] > arr[next])
            {
                next++;
                wins++; 
            }
            else
            {
                wins = 1;
                curr = next;
                next++;
            }
        }
        return arr[curr];
    }
};