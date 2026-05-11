#include <iostream>
using namespace std;

const int MAXN = 3e5;

int N, M;
int arr[MAXN + 1];
int tree[4 * MAXN];

int init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int query(int s, int e, int n, int l, int r) {
    if (l > e || r < s) {
        return 0;
    }
    if (l <= s && e <= r) {
        return tree[n];
    }

    int m = (s + e) / 2;
    return query(s, m, n * 2, l, r) + query(m + 1, e, n * 2 + 1, l, r);
}

void update(int start, int end, int n, int idx, int diff) {
    if (idx < start || idx > end) {
        return;
    }
    tree[n] = tree[n] + diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(start, mid, n * 2, idx, diff);
        update(mid + 1, end, n * 2 + 1, idx, diff);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    init(1, N, 1);
    int l, i, r, s, j, e;
    for (int k = 0; k < M; k++) {
        cin >> l >> i >> r >> s >> j >> e;
        int v1 = query(1, N, 1, l, r);
        int v2 = query(1, N, 1, s, e);
        if (v1 > v2) {
            int v = arr[j] / 2 + (arr[j] % 2);
            update(1, N, 1, i, v);
            update(1, N, 1, j, -v);
            arr[i] = arr[i] + v;
            arr[j] = arr[j] - v;
        } else if (v1 < v2) {
            int v = arr[i] / 2 + (arr[i] % 2);
            update(1, N, 1, i, -v);
            update(1, N, 1, j, v);
            arr[i] = arr[i] - v;
            arr[j] = arr[j] + v;
        }
    }

    for (int k = 1; k <= N; k++) {
        cout << arr[k] << " ";
    }
}