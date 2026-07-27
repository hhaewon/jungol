#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int x;
char action;
int a;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    vector<int> vec(n, x);
    while (true) {
        cin >> action;
        if (action == 'i') {
            cin >> a;
            vec.push_back(a);
        } else if (action == 'r') {
            if (!vec.empty()) {
                vec.pop_back();
            }
        } else if (action == 's') {
            sort(vec.begin(), vec.end());
        } else if (action == 't') {
            if (!vec.empty()) {
                swap(vec.front(), vec.back());
            }
        } else {
            for (auto n : vec) {
                cout << n << " ";
            }
            break;
        }
    }
}