#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int w;
const int coinNumber = 6;
int number[coinNumber];
int ans;
int used[coinNumber];
const int value[6] = {500, 100, 50, 10, 5, 1};
int sum = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> w;
    for (int i = 0; i < coinNumber; i++) {
        cin >> number[i];
        sum += value[i] * number[i];
    }

    w = sum - w;

    for (int i = 0; i < coinNumber; i++) {
        int use;
        if (number[i] * value[i] >= w) {
            use = w / value[i];
        } else {
            use = number[i];
        }
        used[i] = use;
        w -= use * value[i];
    }

    for (int i = 0; i < coinNumber; i++) {
        used[i] = number[i] - used[i];
    }

    for (int i = 0; i < coinNumber; i++) {
        ans += used[i];
    }
    cout << ans << "\n";
    for (int i = 0; i < coinNumber; i++) {
        cout << used[i] << " ";
    }
}