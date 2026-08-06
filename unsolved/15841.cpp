#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int a[100000];
int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N, greater<int>());
    for (int i = 0; i < N; i++) {
        ans = max(ans, a[i] + i + 2);
    }
    cout << ans;
}