// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=daily-question&envId=2024-06-13

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int i = 0;
        int moves = 0;

        while (i < seats.size())
        {
            moves += abs(seats[i] - students[i]);
            i++;
        }

        return moves;
    }
};