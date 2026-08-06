#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Meeting {
    int n;
    int start;
    int end;
    bool operator<(const Meeting& right) const {
        if (end != right.end) {
            return end < right.end;
        }
        return start > right.start;
    }
};

int N;
Meeting meetings[500];
vector<Meeting> used;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int n, s, e;
        cin >> n >> s >> e;
        Meeting meeting = {n, s, e};
        meetings[i] = meeting;
    }
    sort(meetings, meetings + N);
    used.push_back(meetings[0]);
    for (int i = 1; i < N; i++) {
        if (meetings[i].start >= used.back().end) {
            used.push_back(meetings[i]);
        }
    }

    cout << used.size() << "\n";
    for (auto& meeting : used) {
        cout << meeting.n << " ";
    }
}