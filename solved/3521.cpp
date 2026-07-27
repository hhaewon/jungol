#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int weight[5] = {16, 8, 4, 2, 1};
int number[5];
int N;
int ans = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5; i++) {
        cin >> number[4 - i];
    }
    cin >> N;
    for (int i = 0; i < 5; i++) {
        if (N / weight[i] <= number[i]) {
            ans += N / weight[i];
            N = N % weight[i];
        } else {
            ans += number[i];
            N -= weight[i] * number[i];
        }
    }

    if (N > 0) {
        cout << "impossible";
    } else {
        cout << ans;
    }
}