#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> candies(n);
        for (int i = 0; i < n; i++)
        {
            cin >> candies[i];
            candies[i] %= m;
        }

        unordered_map<int, int> chocolates;
        for (int i = 0; i < n; i++)
        {
            int choco;
            cin >> choco;

            chocolates[choco % m]++;
        }

        // For Each Box of Candies
        long long count = 0;
        for (int i = 0; i < n; i++)
        {
            count += chocolates[(m - candies[i]) % m];
        }

        cout << count << endl;
    }
    return 0;
}