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

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        for (int i = 1; i < n / 2; i++)
        {
            cout << i << " ";
            (n % 2 == 0) ? cout << (n - i + 1) : cout << (n - i);
            cout << " ";
        }
        if (n % 2 == 1)
        {
            cout << n;
        }
        cout << endl;
    }
    return 0;
}

// #include <iostream>
// using namespace std;
// #include <vector>

// int main()
// {
//     int T;
//     cin >> T;

//     while (T--)
//     {
//         int n;
//         cin >> n;

//         if (n == 1)
//         {
//             cout << 1 << endl;
//             continue;
//         }

//         int sum = (n * (n + 1)) / 2;

//         int each = sum;
//         for (int i = n - 1; i >= 1; i--)
//         {
//             if (sum % i == 0)
//             {
//                 each = sum / i;
//                 break;
//             }
//         }

//         vector<int> ans;
//         for (int i = 1; i <= n / 2; i++)
//         {
//             ans.push_back(i);
//             ans.push_back(each - i);
//         }
//         if (n % 2 == 1)
//         {
//             ans.push_back(n);
//         }

//         for (int i = 0; i < ans.size(); i++)
//         {
//             cout << ans[i] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }