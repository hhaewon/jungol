#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Data {
    string name;
    int age;
    double blood;

    bool operator<(const Data right) const {
        if (right.blood != blood) {
            return blood < right.blood;
        }
        return age < right.age;
    }
};

priority_queue<Data> pq;
int Q;
string action;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> Q;
    while (Q--) {
        cin >> action;
        if (action == "push") {
            Data data;
            cin >> data.name >> data.age >> data.blood;
            pq.push(data);
        } else {
            if (!pq.empty()) {
                cout << pq.top().name << "\n";
                pq.pop();
            }
        }
    }
}