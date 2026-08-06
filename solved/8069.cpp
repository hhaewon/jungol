#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int Q;
int a[500000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < Q; i++) {
        int b;
        cin >> b;
        int index = lower_bound(a, a + N, b) - a;
        if (index == 0) {
            cout << a[0] << "\n";
        } else if (index == N) {
            cout << a[N - 1] << "\n";
        } else {
            if (a[index] - b < b - a[index - 1]) {
                cout << a[index] << "\n";
            } else {
                cout << a[index - 1] << "\n";
            }
        }
    }
}