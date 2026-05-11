#include <bits/stdc++.h>
using namespace std;

int N;
string B;
string word;
string s;
bool flag = false;

int main() {
    cin >> word;
    cin >> B;
    int BL = B.length();
    int WL = word.length();
    for (int i = 0; i < WL; i++) {
        s.push_back(word[i]);
        int j = 0;
        while (j < s.length() && j < BL && s[s.length() - 1 - j] == B[BL - 1 - j]) {
            j++;
        }
        if (j == BL) {
            for (int k = 0; k < j; k++) {
                s.pop_back();
            }
        }
    }

    if (s.empty()) {
        cout << "FRULA";
    } else {
        cout << s;
    }
}