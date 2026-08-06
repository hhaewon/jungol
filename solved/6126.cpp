#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int diff[1000000 + 2];
int N;
int s, e, c;
int Q;
int A[1000000 + 1];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s >> e >> c;
        diff[s] += c;
        diff[e + 1] -= c;
    }
    for (int i = 1; i <= 1000000 + 1; i++) {
        A[i] = A[i - 1] + diff[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        cout << A[t] << "\n";
    }
}