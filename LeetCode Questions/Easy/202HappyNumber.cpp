// https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150

#include <unordered_map>
using namespace std;

class Solution
{
    unordered_map<int, bool> umap;

public:
    bool isHappy(int n)
    {
        if (n == 1)
        {
            return true;
        }
        if (umap.count(n) > 0)
        {
            return false;
        }
        umap[n] = true;

        int num = 0;
        while (n > 0)
        {
            int rem = n % 10;
            num += rem * rem;

            n /= 10;
        }

        return isHappy(num);
    }
};