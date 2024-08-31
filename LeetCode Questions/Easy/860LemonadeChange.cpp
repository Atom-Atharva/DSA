// https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fives = 0, tens = 0, twenties = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                fives++;
            }
            if (bills[i] == 10)
            {
                tens++;
                if (fives)
                {
                    fives--;
                }
                else
                {
                    return false;
                }
            }
            if (bills[i] == 20)
            {
                twenties++;
                if (tens && fives)
                {
                    tens--;
                    fives--;
                }
                else
                {
                    if (fives >= 3)
                    {
                        fives -= 3;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};