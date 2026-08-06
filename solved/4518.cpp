#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
int m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    if (N < (K + 1) * K / 2) {
        cout << -1;
        return 0;
    }
    m = (N - K * (K + 1) / 2) / K + 1;
    if (N == K * (m - 1) + K * (K + 1) / 2) {
        cout << K - 1;
    } else {
        cout << K;
    }
}