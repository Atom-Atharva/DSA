// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int st = 0, en = numbers.size() - 1;
        while (st < en)
        {
            if (numbers[st] + numbers[en] == target)
            {
                return {st + 1, en + 1};
            }
            else if (numbers[st] + numbers[en] > target)
            {
                en--;
            }
            else
            {
                st++;
            }
        }
        return {-1, -1};
    }
};