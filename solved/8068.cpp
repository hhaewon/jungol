#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M, Q;
int forget[200000];
int memorize[200000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        int n = a / M;
        int remain = a % M;
        if (a <= M) {
            forget[i + 1] -= a;
            forget[i + 2] += a;
        } else {
            forget[i + 1] -= M;
            forget[i + 1 + n] += M - remain;
            forget[i + 2 + n] += remain;
        }
        memorize[i] += a;
    }

    for (int i = 1; i <= N; i++) {
        forget[i] = forget[i - 1] + forget[i];
        memorize[i] = memorize[i - 1] + forget[i] + memorize[i];
    }
    for (int i = 0; i < Q; i++) {
        int a, t;
        cin >> a >> t;
        if (a == 1) {
            cout << memorize[t];
        } else {
            cout << -forget[t];
        }
        cout << "\n";
    }
}