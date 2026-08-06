#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int R, S;
ll a, b;
ll A[501][501];
ll s[501][501];
ll ans = LLONG_MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> S >> a >> b;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= S; j++) {
            cin >> A[i][j];
            s[i][j] = A[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    if (a > b) {
        swap(a, b);
    }
    for (int rx = 1; rx <= R; rx++) {
        for (int lx = 1; lx <= rx; lx++) {
            int ly = 1;
            int ry = 1;
            ll cur;
            while (ry <= S) {
                if (ly > ry) {
                    ry++;
                    continue;
                }
                cur = s[rx][ry] - s[rx][ly - 1] - s[lx - 1][ry] + s[lx - 1][ly - 1];
                if (cur <= a) {
                    ans = min(ans, b - a + 2 * (a - cur));
                    ry++;
                } else if (cur <= b) {
                    ans = b - a;
                    break;
                } else {
                    ly++;
                }
            }
        }
    }
    for (int rx = 1; rx <= R; rx++) {
        for (int lx = 1; lx <= rx; lx++) {
            int ly = 1;
            int ry = 1;
            ll cur;
            while (ry <= S) {
                if (ly > ry) {
                    ry++;
                    continue;
                }
                cur = s[rx][ry] - s[rx][ly - 1] - s[lx - 1][ry] + s[lx - 1][ly - 1];
                if (cur >= b) {
                    ans = min(ans, b - a + 2 * (cur - b));
                    ly++;
                } else if (cur >= a) {
                    ans = b - a;
                    break;
                } else {
                    ry++;
                }
            }
        }
    }

    cout << ans;
}