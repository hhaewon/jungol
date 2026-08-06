#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int dp[301];
int A[301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    dp[1] = A[1];
    if (n >= 2) {
        dp[2] = A[1] + A[2];
    }
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 2] + A[i], dp[i - 3] + A[i - 1] + A[i]);
    }
    cout << dp[n];
}