#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100000;
const ll MAXDISTANCE = 9e18;
int N, M;
vector<pair<int, ll>> graph[MAXN + 1];
ll dist[MAXN + 1];

void dijstra() {
    fill(dist, dist + N + 1, MAXDISTANCE);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [curDist, cur] = pq.top();
        pq.pop();

        for (auto [nxt, cost] : graph[cur]) {
            if (curDist + cost < dist[nxt]) {
                dist[nxt] = curDist + cost;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    dijstra();
    cout << dist[N];
}