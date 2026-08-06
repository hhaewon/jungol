#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int A[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int l = 0;
    int r = N - 1;
    int minl = 0;
    int minr = N - 1;
    int minSum = 2e9 + 1;
    while (l < r) {
        if (abs(A[l] + A[r]) < abs(minSum)) {
            minl = l;
            minr = r;
            minSum = A[l] + A[r];
        }
        if (A[l] + A[r] == 0) {
            break;
        } else if (A[l] + A[r] > 0) {
            r--;
        } else {
            l++;
        }
    }

    cout << A[minl] << " " << A[minr];
}