#include <iostream>
using namespace std;

int N;
int X[250000];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    bool impossible = false;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
        if (i >= 1 && X[i] == X[i - 1] + 1)
        {
            impossible = true;
        }
    }

    if (impossible)
    {
        cout << -1;
    }
    else
    {
        int cnt = 0;
        cnt += (X[0] - 1) / 2 + (X[0] - 1) % 2 + 1;
        for (int i = 0; i < N - 1; i++)
        {
            cnt += (X[i + 1] - X[i] - 2) / 2 + (X[i + 1] - X[i] - 2) % 2 + 1;
        }
        cout << cnt;
    }
}