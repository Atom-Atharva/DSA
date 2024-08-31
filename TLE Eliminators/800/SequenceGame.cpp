// https://codeforces.com/problemset/problem/1862/B

#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int T;
    cin >> T;

    while (T--)
    {

        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> nums;
        nums.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                nums.push_back(arr[i]);
            }
            nums.push_back(arr[i]);
        }

        cout << nums.size() << endl;
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
}