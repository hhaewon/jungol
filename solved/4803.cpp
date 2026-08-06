#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, Q;
pair<ll, ll> A[200001];  // (x, a)
ll T[200001];
ll S[200001];

ll f(ll x) {
    pair<ll, ll> target = {x, (ll)1};
    int k = lower_bound(A + 1, A + N + 1, target) - A;
    return (-S[N] + 2 * S[k - 1]) * x + T[N] - 2 * T[k - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        ll x, a;
        cin >> a >> x;
        A[i] = {x, a};
    }
    sort(A + 1, A + N + 1);
    for (int i = 1; i <= N; i++) {
        auto [x, a] = A[i];
        S[i] = S[i - 1] + a;
        T[i] = T[i - 1] + a * x;
    }

    for (int i = 0; i < Q; i++) {
        ll q;
        cin >> q;
        cout << f(q) << "\n";
    }
}