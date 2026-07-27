#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int A[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int& n : A) {
        cin >> n;
        n++;
    }
    sort(A, A + 10);
    for (int& n : A) {
        cout << n << " ";
    }
}