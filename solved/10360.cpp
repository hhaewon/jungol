#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
void solve() {
    string str;
    int cnt = 0;  // 지금까지 괄호개수
    cin >> str;

    for (auto& c : str) {
        int n = c - '0';
        if (n > cnt) {
            for (int i = 0; i < n - cnt; i++) {
                cout << "(";
            }
            cnt = n;
        } else if (n < cnt) {
            for (int i = 0; i < cnt - n; i++) {
                cout << ")";
            }
            cnt = n;
        }
        cout << n;
    }
    for (int i = 0; i < cnt; i++) {
        cout << ")";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}