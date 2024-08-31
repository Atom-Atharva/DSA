// https://leetcode.com/problems/fraction-addition-and-subtraction/description/?envType=daily-question&envId=2024-08-23

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void addFractions(int currNum, int currDeno, int &num, int &deno)
    {
        num = ((currNum * deno) + (num * currDeno));
        deno = deno * currDeno;

        return;
    }

    void simplifyFraction(int &num, int &deno)
    {
        int en = min(abs(num), abs(deno));
        if (en == 1)
        {
            return;
        }
        if (en == 0)
        {
            deno = 1;
            return;
        }
        for (int i = en; i >= 2; i--)
        {
            if (num % i == 0 && deno % i == 0)
            {
                num /= i;
                deno /= i;
                break;
            }
        }

        return;
    }

    string makeString(int num, int deno)
    {
        string numerator = to_string(num);
        string denominator = to_string(deno);

        return numerator + "/" + denominator;
    }

public:
    string fractionAddition(string expression)
    {
        int num = 0;
        int deno = 1;

        bool isNeg = false;
        bool isNum = true;
        int currNum = 0;
        int currDeno = 0;
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == '-')
            {
                if (isNeg)
                {
                    currNum = 0 - currNum;
                }
                if (currDeno == 0)
                {
                    currDeno = 1;
                }
                addFractions(currNum, currDeno, num, deno);
                currNum = 0;
                currDeno = 0;
                isNeg = true;
                isNum = true;
                continue;
            }
            if (expression[i] == '+')
            {
                if (isNeg)
                {
                    currNum = 0 - currNum;
                }
                if (currDeno == 0)
                {
                    currDeno = 1;
                }
                addFractions(currNum, currDeno, num, deno);
                currDeno = 0;
                currNum = 0;
                isNeg = false;
                isNum = true;
                continue;
            }
            if (expression[i] == '/')
            {
                isNum = false;
                continue;
            }

            if (isNum)
            {
                currNum = currNum * 10 + (expression[i] - '0');
            }
            else
            {
                currDeno = currDeno * 10 + (expression[i] - '0');
            }
        }
        if (isNeg)
        {
            currNum = 0 - currNum;
        }
        if (currDeno == 0)
        {
            currDeno = 1;
        }
        addFractions(currNum, currDeno, num, deno);

        simplifyFraction(num, deno);
        return makeString(num, deno);
    }
};