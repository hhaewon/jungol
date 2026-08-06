#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int W;
pair<int, int> jewel[1000];
int dp[10001];
int ans = -1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        int w, p;
        cin >> w >> p;
        jewel[i] = {w, p};
    }

    for (int i = 1; i <= W; i++) {
        dp[i] = 0;
        for (auto [w, p] : jewel) {
            if (w <= i) {
                dp[i] = max(dp[i], p + dp[i - w]);
            }
        }

        ans = max(dp[i], ans);
    }
    cout << ans;
}