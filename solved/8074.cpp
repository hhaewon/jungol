#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Data {
    int x, y, z;
};

queue<Data> q;
int N;
char action;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    while (N--) {
        cin >> action;
        if (action == 'i') {
            int x, y, z;
            cin >> x >> y >> z;
            Data d = {x, y, z};
            q.push(d);
        } else if (action == 'o') {
            if (q.empty()) {
                cout << "empty\n";
            } else {
                auto [x, y, z] = q.front();
                cout << x << " " << y << " " << z << "\n";
                q.pop();
            }
        } else if (action == 'c') {
            cout << q.size() << "\n";
        } else if (action == 'z') {
            int a;
            cin >> a;
            if (q.empty()) {
                cout << "no\n";
            } else {
                if (q.front().z == a) {
                    cout << "yes\n";
                } else {
                    cout << "no\n";
                }
            }
        }
    }
}