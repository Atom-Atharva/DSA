// https://leetcode.com/problems/remove-k-digits/description/?envType=daily-question&envId=2024-04-11

#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> incOrder;
        for (int i = 0; i < num.size(); i++)
        {
            while (!incOrder.empty() && k > 0 && incOrder.top() > num[i])
            {
                incOrder.pop();
                k--;
            }
            if (incOrder.empty() && num[i] == '0')
            {
                continue;
            }
            incOrder.push(num[i]);
        }

        while (!incOrder.empty() && k > 0)
        {
            incOrder.pop();
            k--;
        }
        if (incOrder.empty())
        {
            return "0";
        }

        int n = num.size() - 1;
        while (!incOrder.empty())
        {
            num[n--] = incOrder.top();
            incOrder.pop();
        }

        return num.substr(n + 1);
    }
};