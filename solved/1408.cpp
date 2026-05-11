#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> edges;
int dp[100];
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        edges.push_back({a, b});
    }
    sort(edges.begin(), edges.end());

    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (edges[j].second < edges[i].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int maxL = -1;
    for (int i = 0; i < N; i++) {
        maxL = max(dp[i], maxL);
    }

    cout << N - maxL;
}
