#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[80];
int N;
bool finished = false;

void solve(int index) {
    if (finished) {
        return;
    }
    for (int length = 1; 2 * length <= index; length++) {
        bool flag = true;
        for (int j = index - 1; j >= index - length; j--) {
            if (arr[j] != arr[j - length]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return;
        }
    }

    if (index == N) {
        for (int i = 0; i < N; i++) {
            cout << arr[i];
        }
        finished = true;
        return;
    }

    for (int i = 1; i <= 3; i++) {
        arr[index] = i;
        solve(index + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    solve(0);
}