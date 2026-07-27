#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int charCount[26];
int N;

void solve() {
    string a, b;
    cin >> a >> b;
    int charCountTempA[26] = {
        0,
    };
    int charCountTempB[26] = {
        0,
    };

    for (auto& c : a) {
        charCountTempA[c - 'a']++;
    }
    for (auto& c : b) {
        charCountTempB[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        charCount[i] += max(charCountTempA[i], charCountTempB[i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        solve();
    }

    for (int i = 0; i < 26; i++) {
        cout << charCount[i] << "\n";
    }
}