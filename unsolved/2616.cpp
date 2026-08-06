#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXM = 1e8;
const int MAXCOST = 10000 + 1;
int dp[101][MAXM + 1];
int N;
int M;
int m[101];
int c[101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> m[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }
    dp[0][0] = 0;
    for (int j = 1; j <= M; j++) {
        dp[0][j] = MAXCOST;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
        }
    }
}