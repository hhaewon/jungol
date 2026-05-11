#include <iostream>
using namespace std;
typedef long long ll;

const int MAXN = 1e6;
ll tree[MAXN * 4];
ll arr[MAXN + 1];
ll N, M;

ll init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll query(int start, int end, int node, int l, int r) {
    if (start > r || end < l) {
        return 0;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(start, mid, node * 2, l, r) + query(mid + 1, end, node * 2 + 1, l, r);
}

void update(int start, int end, int node, int idx, ll v) {
    if (idx < start || idx > end) {
        return;
    }
    tree[node] = tree[node] - arr[idx] + v;

    if (start != end) {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, v);
        update(mid + 1, end, node * 2 + 1, idx, v);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> M;
    init(1, N, 1);
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, N, 1, b, c);
            arr[b] = c;  // 이거 빼먹음.
        } else {
            cout << query(1, N, 1, b, c) << "\n";
        }
    }
}