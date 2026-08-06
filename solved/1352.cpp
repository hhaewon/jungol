#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXW = 30 * 500;
int n, m;
int g[7];
int w[30];
bool dp[31][2 * MAXW + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> g[i];
    }
    for (int i = 0; i <= 30; i++) {
        dp[i][MAXW] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2 * MAXW; j++) {
            int cur = j - MAXW;
            if (cur - w[i] >= -MAXW && dp[i - 1][cur - w[i] + MAXW]) {
                dp[i][j] = true;
            }
            if (cur + w[i] <= MAXW && dp[i - 1][cur + w[i] + MAXW]) {
                dp[i][j] = true;
            }
            if (dp[i - 1][j]) {
                dp[i][j] = true;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (g[i] <= MAXW && dp[n][g[i] + MAXW]) {
            cout << "Y ";
        } else {
            cout << "N ";
        }
    }
}