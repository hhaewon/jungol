#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int A[300000];
int ans = 1;
int pre = -1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    pre = A[0];
    for (int i = 1; i < N; i++) {
        if ((A[i] + pre) % 2 == 1) {
            ans++;
            pre = A[i];
        }
    }

    cout << ans;
}