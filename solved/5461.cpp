#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
ll A[100000];

bool check(ll X) {
    int j = 0;
    for (int i = 0; i < M; i++) {
        ll tsum = 0;
        while (j < N && A[j] + tsum <= X) {
            tsum += A[j];
            j++;
        }
    }
    return j == N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll l = 1;
    ll r = LLONG_MAX;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (check(m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << l;
}