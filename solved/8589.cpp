#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<int, vector<int>, greater<int>> pq;
int N, M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        pq.push(x);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> x;
        int y = pq.top();
        y += x;
        pq.pop();
        pq.push(y);
    }
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}