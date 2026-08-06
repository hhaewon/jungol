#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a;
priority_queue<ll, vector<ll>, greater<ll>> pq;
ll ans;
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < N - 1; i++) {
        int b = pq.top();
        pq.pop();
        b += pq.top();
        pq.pop();
        pq.push(b);
        ans += b;
    }
    cout << ans;
}