#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100000;
const int MAXNUM = 1e9 + 1;
int N, M;
int arr[MAXN + 1];
pair<int, int> tree[4 * MAXN];

void init(int node, int s, int e) {
    tree[node] = {MAXNUM, s};
    if (== e) {
        return;
    }
    int mid = (s + e) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid, r);
}

pair<int, int> query(int node, int s, int e, int l, int r) {
    if (l > e || r < s) {
        return {MAXNUM, l};
    } else if (s <= l && r <= e) {
        return tree[node];
    }
    int mid = (l + r) / 2;
    pair<int, int> v1 = query(2 * node, s, e, l, mid);
    pair<int, int> v2 = query(2 * node + 1, s, e, mid, r);
    return min(v1, v2);
}

void update(int node, int index, int l, int r, int val) {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
}