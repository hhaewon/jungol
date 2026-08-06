#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
ll S[801][801];
ll A[801][801];
ll ans = LLONG_MIN;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
            S[i][j] = A[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        }
    }

    for (int rx = 1; rx <= N; rx++) {
        for (int lx = 1; lx <= rx; lx++) {
            ll minsum = 0;
            for (int i = 1; i <= M; i++) {
                ans = max(ans, S[rx][i] - S[rx][0] - S[lx - 1][i] + S[lx - 1][0] - minsum);
                minsum = min(minsum, S[rx][i] - S[rx][0] - S[lx - 1][i] + S[lx - 1][0]);
            }
        }
    }

    cout << ans;
}