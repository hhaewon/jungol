#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
int h[200000];
int prefixMin;
int prefixMax;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    prefixMin = h[0];
    prefixMax = h[0];

    cout << 1 << " ";
    for (int i = 1; i < N; i++) {
        if (h[i] >= prefixMin - K && h[i] <= prefixMax + K) {
            cout << 1 << " ";
            prefixMin = min(h[i], prefixMin);
            prefixMax = max(h[i], prefixMax);
        } else {
            cout << 0 << " ";
        }
    }
}