#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, d, k, c;
int cnt[3001];
int A[3000000];
int ans = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int l = 0;
    int r = k;  // [l, r)
    for (int i = l; i < r; i++) {
        if (!cnt[A[i]]) {
            ans++;
        }
        cnt[A[i]]++;
    }
    if (!cnt[c]) {
        ans++;
    }
    int cur = ans;
    while (l + 1 < N) {
        if (!cnt[c]) {
            cur--;
        }
        cnt[A[l]]--;
        if (!cnt[A[l]]) {
            cur--;
        }
        if (!cnt[A[r % N]]) {
            cur++;
        }
        cnt[A[r % N]]++;
        if (!cnt[c]) {
            cur++;
        }
        ans = max(cur, ans);
        l++;
        r++;
    }
    cout << ans;
}