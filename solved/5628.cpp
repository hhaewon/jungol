#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, H;
int A[500002];
int S[500001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> H;
    for (int i = 1; i <= N; i++) {
        int h;
        cin >> h;
        if (i & 1) {
            A[1]++;
            A[h + 1]--;
        } else {
            A[H - h + 1]++;
            A[H + 1]--;
        }
    }
    for (int i = 1; i <= H; i++) {
        A[i] = A[i - 1] + A[i];
    }
    int minH = -1;
    int minNum = 2e5 + 1;
    int mincnt = 0;
    for (int i = 1; i <= H; i++) {
        if (A[i] < minNum) {
            minH = i;
            minNum = A[i];
        }
    }
    for (int i = 1; i <= H; i++) {
        if (A[i] == minNum) {
            mincnt++;
        }
    }
    cout << minNum << " " << mincnt;
}