#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 1e5;

typedef struct {
    ll x;
    ll y;
    ll t;
} p;

bool compare(p& a, p& b) {
    return a.t < b.t;
}

int G, N;
p garden[maxN];
p cow[maxN];

bool solve(ll x, ll y, ll t) {
    int start = 0;
    int end = G;
    int mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (garden[mid].t == t) {
            return x != garden[mid].x || y != garden[mid].y;
        } else if (garden[mid].t < t) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    mid = start;
    if (mid == 0) {
        ll cx = garden[0].x;
        ll cy = garden[0].y;
        ll ct = garden[0].t;
        return (x - cx) * (x - cx) + (y - cy) * (y - cy) > (t - ct) * (t - ct);
    }

    if (mid == G) {
        ll cx = garden[G - 1].x;
        ll cy = garden[G - 1].y;
        ll ct = garden[G - 1].t;
        return (x - cx) * (x - cx) + (y - cy) * (y - cy) > (t - ct) * (t - ct);
    }

    ll x1 = garden[mid].x;
    ll y1 = garden[mid].y;
    ll t1 = garden[mid].t;
    ll x2 = garden[mid - 1].x;
    ll y2 = garden[mid - 1].y;
    ll t2 = garden[mid - 1].t;
    return !(((x - x1) * (x - x1) + (y - y1) * (y - y1) <= (t - t1) * (t - t1)) && (x - x2) * (x - x2) + (y - y2) * (y - y2) <= (t - t2) * (t - t2));
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> G >> N;
    int result = 0;

    for (int i = 0; i < G; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        p temp = {a, b, c};
        garden[i] = temp;
    }

    for (int i = 0; i < N; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        p temp = {a, b, c};
        cow[i] = temp;
    }

    sort(garden, garden + G, compare);

    for (int i = 0; i < N; i++) {
        ll x = cow[i].x;
        ll y = cow[i].y;
        ll t = cow[i].t;
        if (solve(x, y, t)) {
            result++;
        }
    }

    cout << result;
}