#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, Q;
map<int, int> citizen;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        citizen[a] = 1;
    }
    bool flag = false;
    for (int i = 0; i < Q; i++) {
        cin >> a;
        if (citizen.find(a) == citizen.end()) {
            cout << a << " ";
            flag = true;
        }
    }
    if (!flag) {
        cout << -1;
    }
}
