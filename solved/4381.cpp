#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5;
int N, M;
int arr[MAXN + 1];
int tree[MAXN + 1];

void update(int index, int diff) {
    int i = index;
    while (i <= N) {
        tree[i] += diff;
        i = i + (i & -i);
    }
}

int query(int e) {
    int i = e;
    int ans = 0;
    while (i >= 1) {
        ans += tree[i];
        i = i - (i & -i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }
    int l, i, r, s, j, e;
    for (int k = 0; k < M; k++) {
        cin >> l >> i >> r >> s >> j >> e;
        int v1 = query(r) - query(l - 1);
        int v2 = query(e) - query(s - 1);
        if (v1 > v2) {
            int v = arr[j] / 2 + (arr[j] % 2);
            update(i, v);
            update(j, -v);
            arr[i] += v;
            arr[j] -= v;
        } else if (v1 < v2) {
            int v = arr[i] / 2 + (arr[i] % 2);
            update(i, -v);
            update(j, v);
            arr[i] -= v;
            arr[j] += v;
        }
    }

    for (int k = 1; k <= N; k++) {
        cout << arr[k] << " ";
    }
}