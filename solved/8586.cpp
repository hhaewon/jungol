#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
array<int, 5> A[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> A[i][j];
        }
        A[i][1] *= -1;
        A[i][3] *= -1;
    }

    sort(A, A + N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 1 || j == 3) {
                cout << -A[i][j] << " ";
            } else {
                cout << A[i][j] << " ";
            }
        }
        cout << "\n";
    }
}