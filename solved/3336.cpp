#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    int x;
    int y;
};

int n;
Point A[100001];
const int OFFSET = 500000;
int v[1000001];
int h[1000001];
int ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        Point p = {x, y};
        A[i] = p;
    }
    A[n] = A[0];
    for (int i = 0; i < n; i++) {
        auto [cx, cy] = A[i];
        auto [nx, ny] = A[i + 1];
        if (cx == nx) {
            int dy = min(cy, ny);
            int uy = max(cy, ny);
            v[dy + OFFSET]++;
            v[uy + OFFSET]--;
        } else {
            int lx = min(cx, nx);
            int rx = max(cx, nx);
            h[lx + OFFSET]++;
            h[rx + OFFSET]--;
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        h[i] = h[i - 1] + h[i];
        v[i] = v[i - 1] + v[i];
        ans = max({ans, h[i], v[i]});
    }
    cout << ans;
}