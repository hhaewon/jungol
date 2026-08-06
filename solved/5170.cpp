#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll H[1000000];
ll M;

bool check(ll h) {
    ll result = 0;
    for (auto& a : H) {
        if (a > h) {
            result += a - h;
        }
    }
    return result >= M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    ll l = 1;
    ll r = 1e9 + 1;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (check(m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << r;
}