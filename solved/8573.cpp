#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int x[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    sort(x, x + N);

    if (N % 2 == 1) {
        cout << x[(N - 1) / 2];
    } else {
        if (x[(N - 1) / 2] != x[(N - 1) / 2 + 1]) {
            cout << x[(N - 1) / 2] << " " << x[(N - 1) / 2 + 1];
        } else {
            cout << x[(N - 1) / 2];
        }
    }
}