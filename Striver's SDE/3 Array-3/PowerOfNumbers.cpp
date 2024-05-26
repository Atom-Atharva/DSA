// https://www.geeksforgeeks.org/problems/power-of-numbers-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution
{
    int M = 1e9 + 7;

public:
    // You need to complete this fucntion

    long long power(int N, int R)
    {
        long long ans = 1;
        while (R > 0)
        {
            if (R % 2 == 1)
            {
                ans = (ans * N) % M;
                R--;
            }
            else
            {
                N = ((long long)N * N) % M;
                R /= 2;
            }
        }
        return ans;
    }
};