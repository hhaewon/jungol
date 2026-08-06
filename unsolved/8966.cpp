#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll A[200000];
ll ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];

        if (A[i] % 3 == 0) {
            ans += A[i] / 3;
            A[i] = 0;
        }
    }
    for (int i = 0; i < N - 1; i++) {
        if (A[i] < A[i + 1]) {
            ll num = min(A[i], A[i + 1] / 2);
            A[i] -= num;
            A[i + 1] -= 2 * num;
            ans += num;
        } else {
            ll num = min(A[i] / 2, A[i + 1]);
            A[i] -= 2 * num;
            A[i + 1] -= num;
            ans += num;
        }
    }
    for (int i = 0; i < N; i++) {
        ans += A[i] / 3;
    }
    cout << ans;
}