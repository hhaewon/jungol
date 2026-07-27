#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
const int MAXN = 100000;
vector<ll> points[MAXN + 1];
ll sum = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        points[y].push_back(x);
    }
    for (int i = 1; i <= N; i++) {
        sort(points[i].begin(), points[i].end());
        if (points[i].size() <= 1) {
            continue;
        }
        sum += points[i][1] - points[i][0];
        sum += points[i][points[i].size() - 1] - points[i][points[i].size() - 2];
        for (int j = 1; j < points[i].size() - 1; j++) {
            sum += min(points[i][j] - points[i][j - 1], points[i][j + 1] - points[i][j]);
        }
    }

    cout << sum;
}