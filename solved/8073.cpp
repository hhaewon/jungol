#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, a;
stack<int> s;
char action;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> action;
        if (action == 'i') {
            cin >> a;
            s.push(a);
        } else if (action == 'o') {
            if (s.empty()) {
                cout << "empty\n";
            } else {
                cout << s.top() << "\n";
                s.pop();
            }
        } else {
            cout << s.size() << "\n";
        }
    }
}
