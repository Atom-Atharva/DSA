// https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    int N;
    cin >> N;

    vector<int> soldiers(N);
    for (int i = 0; i < N; i++)
    {
        cin >> soldiers[i];
    }

    int Q;
    cin >> Q;

    sort(soldiers.begin(), soldiers.end());

    while (Q--)
    {
        int power;
        cin >> power;

        int i = 0;
        int sum = 0;
        while (i < soldiers.size() && soldiers[i] <= power)
        {
            sum += soldiers[i];
            i++;
        }

        cout << i << " " << sum << endl;
    }

    return 0;
}