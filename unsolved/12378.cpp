#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int giveCount[200001];
int givenCount[200001];
int oneGivePerson = -1;
int oneGivenPerson = -1;

vector<int> give[200001];

void solve() {
    cin >> N;
    for (int i = 0; i < 2 * N - 1; i++) {
        int a, b;
        cin >> a >> b;
        giveCount[a]++;
        givenCount[b]++;
        give[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        if (giveCount[i] >= 3 || giveCount[i] == 0) {
            cout << "NO";
            return;
        }
        if (giveCount[i] == 1) {
            if (oneGivePerson != -1) {
                cout << "NO";
                return;
            }
            oneGivePerson = i;
        }

        if (givenCount[i] >= 3 || givenCount[i] == 0) {
            cout << "NO";
            return;
        }

        if (givenCount[i] == 1) {
            if (oneGivenPerson != -1) {
                cout << "NO";
                return;
            }
            oneGivenPerson = i;
        }
    }

    if (oneGivenPerson == oneGivePerson || give[oneGivePerson][0] == oneGivenPerson) {
        cout << "NO";
    } else {
        cout << "YES\n";
        cout << oneGivePerson << " " << oneGivenPerson;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}
