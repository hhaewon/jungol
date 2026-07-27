#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Meeting {
    int order;
    int start;
    int end;

    bool operator<(const Meeting Right) const {
        int length1 = end - start;
        int length2 = Right.end - Right.start;
        if (length1 != length2) {
            return length1 < length2;
        }
        return start < Right.start;
    }
};

int N;
Meeting meetings[500000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int s, e;
    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        meetings[i].order = i + 1;
        meetings[i].start = s;
        meetings[i].end = e;
    }

    sort(meetings, meetings + N);
    for (int i = 0; i < N; i++) {
        cout << meetings[i].order << "\n";
    }
}