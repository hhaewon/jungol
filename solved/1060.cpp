#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UF {
    int N;
    ll par[101];

    void init() {
        iota(par + 1, par + N + 1, (ll)1);
    }

    ll find(ll v) {
        if (v == par[v]) {
            return v;
        }
        return par[v] = find(par[v]);
    }

    void union_(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (u == v) {
            return;
        }
        par[u] = v;
    }
};

struct Edge {
    ll w, u, v;

    bool operator<(const Edge& right) const {
        return w < right.w;
    }
};

int N;
vector<Edge> edges;
ll ans = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    UF uf;
    uf.N = N;
    uf.init();
    edges.resize(N * N);
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            ll w;
            cin >> w;
            Edge edge = {w, i, j};
            edges.push_back(edge);
        }
    }

    sort(edges.begin(), edges.end());
    for (auto& edge : edges) {
        auto [w, u, v] = edge;
        if (uf.find(u) != uf.find(v)) {
            ans += w;
            uf.union_(u, v);
        }
    }

    cout << ans;
}