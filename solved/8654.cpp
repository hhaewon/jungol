#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, T;
ll A[200000];

bool check(ll X) {
    ll result = 0;
    for (auto a : A) {
        result += min(a, X);
    }
    return result >= T;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll l = 1;
    ll r = 1e10 + 1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l << "\n";
}