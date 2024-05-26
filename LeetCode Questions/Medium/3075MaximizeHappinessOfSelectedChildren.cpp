// https://leetcode.com/problems/maximize-happiness-of-selected-children/?envType=daily-question&envId=2024-05-09

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += (happiness[i] - i > 0) ? happiness[i] - i : 0;
        }

        return sum;
    }
};

class Solution1
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        priority_queue<int> children;
        for (int i = 0; i < happiness.size(); i++)
        {
            children.push(happiness[i]);
        }

        long long int happy = 0;

        int i = 0;
        while (i < k)
        {
            happy += (children.top() - i > 0) ? children.top() - i : 0;
            children.pop();

            i++;
        }

        return happy;
    }
};