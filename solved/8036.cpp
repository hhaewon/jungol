#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int, ll> x;
map<int, ll> y;
int N;
ll ans = 0;

ll comb(ll n) {
    return n * (n - 1) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        x[a]++;
        y[b]++;
    }

    for (auto& [_, n] : x) {
        ans += comb(n);
    }
    for (auto& [_, n] : y) {
        ans += comb(n);
    }
    cout << ans;
}