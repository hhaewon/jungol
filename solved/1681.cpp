#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int cost[14][14];
int ans = 1e6;
int temp;
bool used[14];

void solve(int start, int index) {
    if (index == N - 1) {
        if (!cost[start][1]) {
            return;
        }
        temp += cost[start][1];
        ans = min(ans, temp);
        temp -= cost[start][1];
        return;
    }
    if (temp > ans) {
        return;
    }

    for (int i = 2; i <= N; i++) {
        if (!used[i] && cost[start][i]) {
            used[i] = true;
            temp += cost[start][i];
            solve(i, index + 1);
            temp -= cost[start][i];
            used[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> cost[i][j];
        }
    }

    solve(1, 0);
    if (ans == 1e6) {
        cout << 0;
    } else {
        cout << ans;
    }
}