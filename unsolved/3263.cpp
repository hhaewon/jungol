#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 2e6;
vector<ll> arr(MAXN * 2);
ll N;
vector<pair<ll, ll>> dp(MAXN * 2);

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[N + i] = arr[i];
    }
    dp[0].first = arr[0];
    dp[0].second = 1;
    for (int i = 1; i < 2 * N; i++) {
        dp[i].first = arr[i];
        dp[i].second = 1;
        if (dp[i - 1].first + arr[i] > dp[i].first && dp[i - 1].second < N) {
            dp[i].first = dp[i - 1].first + arr[i];
            dp[i].second = dp[i - 1].second + 1;
        }
        if (dp[i - 1].second == N && dp[i - 1].first - arr[i - N] + arr[i] > dp[i].first) {
            dp[i].first = dp[i - 1].first - arr[i - N] + arr[i];
            dp[i].second = N;
        }
    }

    ll maxval = dp[0].first;
    for (int i = 0; i < 2 * N; i++) {
        cout << dp[i].first << " ";
        maxval = max(maxval, dp[i].first);
    }
    cout << maxval;
}