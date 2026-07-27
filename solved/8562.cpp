#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Q;
char action;
int x;
map<int, int> m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    while (Q--) {
        cin >> action;
        if (action == 'f') {
            cin >> x;
            if (m.find(x) != m.end()) {
                cout << "YES " << m[x] << "\n";
            } else {
                cout << "NO\n";
            }
        } else if (action == 'a') {
            cin >> x;
            m[x] += 1;
        } else {
            cout << m.size() << "\n";
        }
    }
}