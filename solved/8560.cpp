#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, string> A[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (auto& [age, name] : A) {
        cin >> name >> age;
        age *= -1;
    }

    sort(A, A + 10);
    for (auto& [age, name] : A) {
        cout << name << " " << -age << "\n";
    }
}