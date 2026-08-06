#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int a[10000];
int M;

bool check(int X) {
    int result = 0;
    for (auto& c : a) {
        result += min(c, X);
    }
    return result <= M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> M;

    int l = 1;
    int r = 1e5 + 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    int ans = 0;
    for (auto c : a) {
        ans = max(ans, min(c, r));
    }
    cout << ans;
}