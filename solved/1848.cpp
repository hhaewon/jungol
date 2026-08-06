#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int M;
vector<int> fixedPoint;
int dp[41];
int ans = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        fixedPoint.push_back(x);
    }
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 40; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int prev = 0;
    for (auto& cur : fixedPoint) {
        ans *= dp[cur - prev - 1];
        prev = cur;
    }
    ans *= dp[N - prev];
    cout << ans;
}