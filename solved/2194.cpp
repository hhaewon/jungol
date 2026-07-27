#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, S;
ll C[100000];
ll Y[100000];

ll ans;
ll minCost = 10001;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> C[i] >> Y[i];
    }

    for (int i = 0; i < N; i++) {
        if (C[i] < minCost) {
            ans += C[i] * Y[i];
            minCost = C[i];
        } else {
            ans += minCost * Y[i];
        }
        minCost += S;
    }
    cout << ans;
}