#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, W;
int w[1001];
int p[1001];
int dp[1001][10001];  // dp[i][j]:  i이전, 무게 j 최대가치
int ans = -1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> p[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + p[i]);
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
}
