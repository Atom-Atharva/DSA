// https://codeforces.com/problemset/problem/1850/D

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int count = 1;
    int maxCount = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - nums[i - 1] > k)
        {
            maxCount = max(maxCount, count);
            count = 0;
        }
        count++;
    }
    maxCount = max(maxCount, count);

    cout << n - maxCount << endl;

    return;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}