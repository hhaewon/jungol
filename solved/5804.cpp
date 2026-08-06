#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
int X[200000];

bool check(int d) {
    int i = 0;
    for (int j = 0; j < K - 1; j++) {
        int next = lower_bound(X, X + N, X[i] + d) - X;
        if (next == N) {
            return false;
        }
        i = next;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    sort(X, X + N);
    int l = 1;
    int r = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r;
}