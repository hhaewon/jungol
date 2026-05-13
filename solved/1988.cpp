#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
ll K;

ll power(ll a, int n) {
    if (n == 0) {
        return 1;
    }
    ll sub = pow(a, n / 2);
    ll result = sub * sub;
    if (n % 2) {
        result *= a;
    }
    return result;
}

void solve(int start, int end, int via, int n, ll k) {
    ll temp = pow(2, n - 1) - 1;
    if (k <= temp) {
        solve(start, via, end, n - 1, k);
    } else if (k == temp + 1) {
        cout << n << " : " << start << " -> " << end << "\n";
        return;
    } else {
        solve(via, end, start, n - 1, k - temp - 1);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    solve(1, 3, 2, N, K);
}