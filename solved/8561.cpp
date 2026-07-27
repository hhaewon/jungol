#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string name;
    int i = 1;
    cin >> name;
    while (name != "end") {
        m[name] = i++;
        cin >> name;
    }

    cout << m.size() << "\n";
    for (auto& [name, line] : m) {
        cout << name << " " << line << "\n";
    }
}