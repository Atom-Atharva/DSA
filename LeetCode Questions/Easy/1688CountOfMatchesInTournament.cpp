// https://leetcode.com/problems/count-of-matches-in-tournament/?envType=daily-question&envId=2023-12-05

#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfMatches(int n)
    {
        // Base Case--
        if (n == 1)
        {
            return 0;
        }

        // Current Round--
        int teams = (n % 2 == 0) ? n / 2 : (n - 1) / 2;

        // Recursive Call--
        int match = (n % 2 == 0) ? numberOfMatches(n / 2) : numberOfMatches(((n - 1) / 2) + 1);
    
        return match + teams;
    }
};