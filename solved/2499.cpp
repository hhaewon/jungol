#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int a[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N);
    int psum = 0;
    int ans = 0;
    if (a[0] != 1) {
        ans = 1;
    } else {
        psum = a[0];
        for (int i = 1; i < N; i++) {
            if (psum + 1 < a[i]) {
                ans = psum + 1;
                break;
            }
            psum += a[i];
        }
        if (ans == 0) {
            ans = psum + 1;
        }
    }

    cout << ans;
}