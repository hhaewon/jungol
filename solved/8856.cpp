#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int A[100000];
int x, y;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> x >> y;
    reverse(A + x, A + y + 1);
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }

    cout << "\n";
    sort(A, A + N);
    reverse(A, A + N);
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
}