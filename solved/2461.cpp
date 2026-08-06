#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int DAYOFMONTH[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int MONTH[13];
int N;
vector<int> flower[365];
int dp[365];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 12; i++) {
        MONTH[i] = MONTH[i - 1] + DAYOFMONTH[i - 1];
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        int s = MONTH[sm] + sd - 1;
        int e = MONTH[em] + ed - 1;
        flower[s].push_back(e);
    }

    for (int i = 0; i < 365; i++) {
        dp[i] = -1;
        if (i >= 1) {
            dp[i] = max(-1, dp[i - 1]);
        }
        for (auto& e : flower[i]) {
            dp[i] = max(dp[i], e);
        }
        // cout << i << " " << dp[i] << "\n";
    }
    int cur = MONTH[3];
    int end = MONTH[11] + 29;
    int cnt = 0;
    while (cur <= end) {
        if (dp[cur] == -1 || dp[cur] <= cur) {
            cout << 0;
            return 0;
        }
        cur = dp[cur];
        cnt++;
    }
    cout << cnt;
}