#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int A[1000000];
int ans;
int m;
int a, r;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        m += A[i];
    }
    sort(A, A + n, greater<int>());
    a = m / n;
    r = m % n;
    for (int i = 0; i < r; i++) {
        ans += abs((a + 1) - A[i]);
    }
    for (int i = r; i < n; i++) {
        ans += abs(a - A[i]);
    }
    cout << ans / 2;
}
