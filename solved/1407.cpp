#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXNUM = 34;
ll ans;
string A;
ll dp[41];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A;
    dp[0] = 1;
    dp[1] = A[0] != 0 ? 1 : 0;
    for (int i = 2; i <= A.size(); i++) {
        int d1 = A[i - 2] - '0';
        int d2 = A[i - 1] - '0';
        int num = 10 * d1 + d2;
        if (d1 == 0 && d2 == 0) {
            dp[i] = 0;
        } else if (d1 == 0 && d2 != 0) {
            dp[i] = dp[i - 1];
        } else if (d1 != 0 && d2 == 0) {
            if (num <= MAXNUM) {
                dp[i] = dp[i - 2];
            } else {
                dp[i] = 0;
            }
        } else {
            if (num <= MAXNUM) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }
    }
    cout << dp[A.size()];
}