#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A[1001][1001];
ll psum[1001][1001];
int N, Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + A[i][j];
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int sri, sci, eri, eci;
        cin >> sri >> sci >> eri >> eci;
        cout << psum[eri][eci] - psum[sri - 1][eci] - psum[eri][sci - 1] + psum[sri - 1][sci - 1] << "\n";
    }
}