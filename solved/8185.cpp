#include <bits/stdc++.h>
using namespace std;

int n;
int nextFriend[100001];
int state[100001];
bool visited[100001];

void find(int cur) {
    vector<int> taken;
    taken.push_back(cur);
    visited[cur] = true;
    while (!visited[nextFriend[cur]]) {
        cur = nextFriend[cur];
        taken.push_back(cur);
        visited[cur] = true;
    }

    if (state[nextFriend[cur]] != 0) {
        for (auto& k : taken) {
            state[k] = 1;
        }
        return;
    }

    int i = 0;
    for (; i < taken.size(); i++) {
        if (taken[i] != nextFriend[cur]) {
            state[taken[i]] = 1;
        } else {
            state[taken[i]] = 2;
            break;
        }
    }
    for (; i < taken.size(); i++) {
        state[taken[i]] = 2;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> nextFriend[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            find(i);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (state[i] == 1) {
            cnt++;
        }
    }
    cout << cnt;
}