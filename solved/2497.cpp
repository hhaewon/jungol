#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
int A[100001];
int ans = -1;
int cur;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < K; i++) {
        cur += A[i];
    }
    ans = cur;
    for (int i = K; i < N; i++) {
        cur = cur + A[i] - A[i - K];
        ans = max(ans, cur);
    }
    cout << ans;
}