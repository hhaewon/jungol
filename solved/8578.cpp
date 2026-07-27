#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int A[200000];
int minDiff = 1e9;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A, A + N);
    for (int i = 0; i + 1 < N; i++) {
        minDiff = min(minDiff, A[i + 1] - A[i]);
    }
    cout << minDiff;
}