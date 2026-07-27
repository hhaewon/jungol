#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

deque<int> q;
int x;
int N;
string action;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while (N--) {
        cin >> action;
        if (action == "call") {
            cin >> x;
            q.push_back(x);
        } else if (action == "wait") {
            cin >> x;
            while (!q.empty() && x > 0 && x >= q.front()) {
                x -= q.front();
                q.pop_front();
            }
            if (!q.empty()) {
                q[0] -= x;
            }
        } else {
            int A = q.size();
            int B = 0;
            for (auto& n : q) {
                B += n;
            }
            cout << A << " people " << B << " minutes\n";
        }
    }
}