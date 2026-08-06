#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int coin[10];
int W;
int dp[64001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    cin >> W;
    for (int i = 1; i <= W; i++) {
        dp[i] = 64001;
        for (int j = 0; j < N; j++) {
            if (coin[j] <= i) {
                dp[i] = min(dp[i], 1 + dp[i - coin[j]]);
            }
        }
    }

    if (dp[W] == 64001) {
        cout << "impossible";
    } else {
        cout << dp[W];
    }
}