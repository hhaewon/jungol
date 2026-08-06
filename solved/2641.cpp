#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, C, M;
vector<pair<int, int>> boxes[2001];
priority_queue<pair<int, int>> used;
int usedcnt[2001];
int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        boxes[s].push_back({e, c});
    }
    int cur = 0;
    for (int i = 1; i <= N; i++) {
        ans += usedcnt[i];
        cur -= usedcnt[i];
        for (auto& [end, c] : boxes[i]) {
            used.push({end, c});
            usedcnt[end] += c;
            cur += c;
        }
        while (cur > C) {
            auto [end, c] = used.top();
            if (cur - c > C) {
                cur -= c;
                usedcnt[end] -= c;
                used.pop();
            } else {
                used.push({end, c - cur + C});
                usedcnt[end] -= cur - C;
                cur = C;
                used.pop();
            }
        }
    }
    cout << ans;
}