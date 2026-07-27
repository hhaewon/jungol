#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string line;
int ans;
int k;
int N;
bool used[20000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> k;
    cin >> line;
    for (int i = 0; i < N; i++) {
        if (line[i] == 'H') {
            continue;
        }
        for (int j = max(0, i - k); j <= i + k && j < N; j++) {
            if (line[j] == 'H' && !used[j]) {
                ans++;
                used[j] = true;
                break;
            }
        }
    }

    cout << ans;
}