// https://www.interviewbit.com/problems/subarray-with-given-xor/

//************************ GOOD QUESTION ******************************//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int solve(vector<int> &A, int B)
    {
        unordered_map<int, int> prefXOR;
        prefXOR[0] = 1;

        int XOR = 0;
        int count = 0;
        for (int i = 0; i < A.size(); i++)
        {
            XOR ^= A[i];
            if (prefXOR.count(XOR ^ B))
            {
                count += prefXOR[XOR ^ B];
            }
            prefXOR[XOR]++;
        }

        return count;
    }
};