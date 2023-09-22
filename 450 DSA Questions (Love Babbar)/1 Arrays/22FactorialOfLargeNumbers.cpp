// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

// Given an integer N, find its factorial. return a list of integers denoting the digits that make up the factorial of N.

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> factorial(int N)
    {
        vector<int> ans;
        ans.push_back(1);
        // Multiplication--
        for (int i = 2; i <= N; i++)
        {
            // Multiplication with current number(i)--
            int carry = 0;
            for (int j = 0; j < ans.size(); j++)
            {
                int num = i * ans[j] + carry;
                int rem = num % 10;
                carry = num / 10;
                ans[j] = rem;
            }

            // Insert Remaining Carry into array--
            while (carry != 0)
            {
                ans.push_back(carry % 10);
                carry /= 10;
            }
        }

        // Reverse Array--
        for (int i = 0; i < ans.size() / 2; i++)
        {
            int temp = ans[i];
            ans[i] = ans[ans.size() - i - 1];
            ans[ans.size() - i - 1] = temp;
        }

        return ans;
    }
};