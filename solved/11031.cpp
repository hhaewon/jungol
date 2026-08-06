#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, b, a;
ll curCost;
ll cost[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b >> a;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    sort(cost, cost + n);
    int k = 0;
    while (curCost <= b && k < n) {
        if (k < a) {
            curCost += cost[k] / 2;
        } else {
            curCost += cost[k] / 2;
            curCost += cost[k - a] / 2;
        }
        k++;
    }
    if (curCost <= b) {
        cout << k;
    } else {
        cout << k - 1;
    }
}
