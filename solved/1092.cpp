#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 20091024;

ll pow(ll x, ll n) {
    if (n == 0) {
        return 1;
    }
    ll sub = pow(x, n / 2);
    ll result = sub * sub % MOD;
    if (n & 1) {
        result = (result * x) % MOD;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x, y;
    cin >> x >> y;
    cout << pow(x, y);
}