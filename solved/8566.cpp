#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll P;
ll A[500000];
priority_queue<ll, vector<ll>, greater<>> pq;
ll curSum = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> P;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        pq.push(A[i]);
        curSum += A[i];
        if (curSum < P) {
            cout << -1 << " ";
        } else {
            while (curSum - pq.top() >= P) {
                curSum -= pq.top();
                pq.pop();
            }
            cout << pq.size() << " ";
        }
    }
}