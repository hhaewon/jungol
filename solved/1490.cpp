#include <bits/stdc++.h>
using namespace std;

int N, K;
int target[11];
int used[11];
bool finished = false;
bool printed = false;

void makeComb(int index) {
    if (printed) {
        return;
    }
    if (index == K + 1) {
        for (int i = 1; i <= K; i++) {
            if (used[i] != target[i]) {
                if (finished) {
                    for (int j = 1; j <= K; j++) {
                        cout << used[j] << " ";
                    }
                    printed = true;
                }
                return;
            }
        }
        finished = true;
        return;
    }

    for (int i = used[index - 1] + 1; i <= N; i++) {
        used[index] = i;
        makeComb(index + 1);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        cin >> target[i];
    }
    makeComb(1);
    if (!printed) {
        cout << "NONE";
    }
}