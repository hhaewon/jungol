#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 1000;
    for (int x = 0; a * x <= d; x++) {
        for (int y = 0; a * x + b * y <= d; y++) {
            if ((d - a * x - b * y) % c == 0) {
                ans = min(ans, x + y + (d - a * x - b * y) / c);
            }
        }
    }

    cout << ans;
}