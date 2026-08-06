#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll A[1000001];
ll psum[1000001];
int Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        psum[i] = psum[i - 1] + A[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int s, e;
        cin >> s >> e;
        cout << psum[e] - psum[s - 1] << "\n";
    }
}