#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
ll A[100001];
ll S[100001];
ll ans = LLONG_MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++) {
        S[i] = S[i - 1] + A[i];
    }
    ll cur = 0;
    for (int j = 1; j <= k; j++) {
        cur += (-k - 1 + 2 * j) * A[j];
    }
    ans = cur;
    for (int i = 2; i + k - 1 <= n; i++) {
        cur = cur + (k - 1) * A[i + k - 1] + (k - 1) * A[i - 1] - 2 * (S[i + k - 2] - S[i - 1]);
        ans = min(cur, ans);
    }
    cout << ans;
}