#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
ll a[200000];
ll ans = 0;

void solve() {
    sort(a, a + N, greater<ll>());
    for (int i = 1; i < N; i++) {
        if ((a[i - 1] - a[i]) % 2 != 0) {
            cout << -1;
            return;
        }
        if (a[i - 1] != a[i]) {
            ans += ((a[i - 1] - a[i]) / 2) * i;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    solve();
}