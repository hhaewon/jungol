#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v[1000];
int n;
int m;
int a[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        v[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (auto& num : v[a[i]]) {
            cout << num << " ";
        }
        cout << "\n";
    }
}