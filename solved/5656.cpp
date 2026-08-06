#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5;
string input;
int a[MAXN + 1];
int S[MAXN + 1];
int n;
map<int, int> m;
ll ans;

ll comb(ll n) {
    return n * (n - 1) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> input;
    for (int i = 1; i <= n; i++) {
        a[i] = input[i - 1] - '0';
    }
    m[0]++;
    for (int i = 1; i <= n; i++) {
        S[i] = S[i - 1] + a[i];
        m[S[i] - i]++;
    }
    for (auto& [k, v] : m) {
        ans += comb((ll)v);
    }
    cout << ans;
}