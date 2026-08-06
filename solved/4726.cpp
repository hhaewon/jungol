#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int A[100001];
int S[100001];
int ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }
    for (int i = 2; i <= N - 1; i++) {
        ans = max(S[i] + S[N - 1] - 2 * A[i], ans);
        ans = max(S[N - 1] - S[1] + A[i], ans);
        ans = max(S[N] - A[1] + S[N] - S[i - 1] - 2 * A[i], ans);
    }
    cout << ans;
}