#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5;
int N;
int A[MAXN + 1];
int psum[MAXN + 1];
int pmin = 0;
int maxdiff = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        psum[i] = A[i] + psum[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        maxdiff = max(maxdiff, psum[i] - pmin);
        pmin = min(pmin, psum[i]);
    }
    cout << maxdiff;
}