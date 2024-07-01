#include <iostream>
#include <vector>
using namespace std;

void generateArray(int N)
{
    vector<int> result;
    if (N == 1)
    {
        result.push_back(1);
    }
    else
    {
        for (int i = 0; i < N - 1; ++i)
        {
            if (i % 2 == 0)
            {
                result.push_back(7);
            }
            else
            {
                result.push_back(5);
            }
        }
        result.push_back(3);
    }
    for (int i = 0; i < N; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        generateArray(N);
    }

    return 0;
}
