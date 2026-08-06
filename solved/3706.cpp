#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> m;
int n;
ll A[100001];
ll psum[100001];
ll ans;
ll comb(ll n) {
    return n * (n - 1) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        psum[i] = psum[i - 1] + A[i];
        m[psum[i]]++;
    }
    m[0]++;
    for (auto& [k, v] : m) {
        ans += comb(v);
    }

    cout << ans;
}