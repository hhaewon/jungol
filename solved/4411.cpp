#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[31][31];  // dp[i][j] iCj
int n, k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 30; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    cin >> n >> k;
    cout << dp[n][k];
}