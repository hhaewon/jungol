#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
map<string, ll> m;
ll result;

vector<string> split(string input, string delimiter) {
    vector<string> ret;
    int pos = 0;
    string token = "";
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string city, state;
        cin >> city;
        cin >> state;
        string code = city.substr(0, 2) + state;
        m[code]++;
    }
    for (auto& [code, n] : m) {
        string code2 = code.substr(2, 2) + code.substr(0, 2);
        if (code != code2) {
            result += n * m[code2];
        }
    }
    cout << result / 2;
}