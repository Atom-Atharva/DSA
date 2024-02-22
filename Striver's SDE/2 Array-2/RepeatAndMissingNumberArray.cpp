// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> repeatedNumber(const vector<int> &A);
};

vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    // Memory Block
    vector<int> freq(A.size(), 0);

    for (int i = 0; i < A.size(); i++)
    {
        freq[A[i] - 1]++;
    }

    // Output Array
    vector<int> output(2, -1);
    for (int i = 0; i < A.size(); i++)
    {
        if (freq[i] > 1)
        {
            output[0] = i + 1;
        }
        if (freq[i] == 0)
        {
            output[1] = i + 1;
        }
    }

    return output;
}
