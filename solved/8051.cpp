#include <iostream>
using namespace std;
typedef long long ll;

const int MAX = 10000;
ll dp1[MAX + 1];
ll dp2[MAX + 1];
ll dp3[MAX + 1];
int a;
int N;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    dp1[0] = 1;
    dp2[0] = 1;
    dp2[1] = 0;

    for (int k = 0; k <= MAX; k++) {
        if (k % 3 == 0) {
            dp3[k] = 1;
        } else {
            dp3[k] = 0;
        }
    }
    for (int k = 2; k <= MAX; k++) {
        dp2[k] = dp3[k] + dp2[k - 2];
    }
    for (int k = 1; k <= MAX; k++) {
        dp1[k] = dp1[k - 1] + dp2[k];
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        cout << dp1[a] << " ";
    }
}