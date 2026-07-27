#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

int N;
pii A[100000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + N);
    for (int i = 0; i < N; i++) {
        cout << A[i].first * A[i].second << "\n";
    }
}