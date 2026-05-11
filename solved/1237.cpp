#include <bits/stdc++.h>
using namespace std;

int N;
string A[18];
int result[19];
int arr[18];

void back(int n, int start, int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (A[arr[i]][arr[j]] == '0') {
                    return;
                }
            }
        }
        result[n]++;
        return;
    }
    if (index == N) {
        return;
    }
    for (int i = start; i < N; i++) {
        arr[index] = i;
        back(n, i + 1, index + 1);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        back(i, 0, 0);
    }
    for (int i = 1; i < N; i++) {
        cout << result[i] << ", ";
    }
    cout << result[N];
}