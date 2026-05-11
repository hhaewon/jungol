#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
ll s;
ll A[200000];

void solve()
{
    ll result;
    if (N % 2 == 0)
    {
        result = s;
    }
    else
    {
        result = -s;
    }
    int i = 0;
    for (i = 0; i < N / 2; i++)
    {
        result -= 2 * A[i];
    }
    for (; i < N; i++)
    {
        result += 2 * A[i];
    }
    cout << result;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> s;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A, A + N);
    solve();
}